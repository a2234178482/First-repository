#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

//用户数据结构
typedef struct USER {
    int id;
    char username[50];
    char password[50];
} user;

//游戏日志数据结构
typedef struct LOG {
    int user_id;
    char username[50];
    char start_time[30];
    int duration; // 游戏持续时间（秒）
    int score;
} log;

//全局变量
user current_user; // 当前登录用户
time_t game_start_time; // 游戏开始时间

#define U 1
#define D 2
#define L 3 
#define R 4       //方向状态 U:上 D:下 L:左 R:右

typedef struct SNAKE //蛇的一个节点
{
    int x;
    int y;
    struct SNAKE* next;
}snake;

//全局变量
int score = 0, add = 10;//总得分 每次吃食物得分
int status = R, sleeptime = 200;//移动方向 每次移动的间隔时间
snake* head, * food;//蛇头指针 食物指针
snake* q;//遍历蛇的时候用到的指针
int endgamestatus = 0; //游戏结束状态 1：撞到墙壁 2：咬到自己 3：主动退出游戏

//全局函数声明
void Pos(int x, int y);
void creatMap();
void initsnake();
int biteself();
void createfood();
void cantcrosswall();
void snakemove();
void pause();
void gamecircle();
void welcometogame();
void endgame();
void gamestart();
void restart_game();

//用户系统函数
void register_user();
int login_user();
void save_user_data();
void load_user_data();
void save_game_log();
void show_game_logs();

//设置光标位置
void Pos(int x, int y)
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}

//创建游戏地图
void creatMap()
{
    int i;
    for (i = 0; i < 58; i += 2)//打印上下边框
    {
        Pos(i, 0);
        printf("■");
        Pos(i, 26);
        printf("■");
    }
    for (i = 1; i < 26; i++)//打印左右边框
    {
        Pos(0, i);
        printf("■");
        Pos(56, i);
        printf("■");
    }
}

//初始化蛇身
void initsnake()
{
    snake* tail;
    int i;
    tail = (snake*)malloc(sizeof(snake));//从蛇尾开始向蛇头初始化 设置初始坐标
    tail->x = 24;
    tail->y = 5;
    tail->next = NULL;
    for (i = 1; i <= 4; i++)
    {
        head = (snake*)malloc(sizeof(snake));
        head->next = tail;
        head->x = 24 + 2 * i;
        head->y = 5;
        tail = head;
    }
    while (tail != NULL)//从蛇头到蛇尾打印蛇身
    {
        Pos(tail->x, tail->y);
        printf("■");
        tail = tail->next;
    }
}

//判断是否咬到自己
int biteself()
{
    snake* self;
    self = head->next;
    while (self != NULL)
    {
        if (self->x == head->x && self->y == head->y)
        {
            return 1;
        }
        self = self->next;
    }
    return 0;
}

//随机生成食物
void createfood()
{
    snake* food_1;
    srand((unsigned)time(NULL));
    food_1 = (snake*)malloc(sizeof(snake));
    if (food_1 == NULL)
    {
        exit(1);
    }
    do
    {
        food_1->x = rand() % 52 + 2; // x范围：2-54
    } while ((food_1->x % 2) != 0);    //保证x为偶数 让食物能与蛇头对齐
    food_1->y = rand() % 24 + 1; // y范围：1-25
    q = head;
    while (q != NULL)
    {
        if (q->x == food_1->x && q->y == food_1->y) //判断食物是否与蛇身重合
        {
            free(food_1);
            createfood();
            return;
        }
        q = q->next;
    }
    Pos(food_1->x, food_1->y);
    food = food_1;
    printf("●");
}

//禁止穿墙
void cantcrosswall()
{
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
    {
        endgamestatus = 1;
        endgame();
    }
}

//蛇移动 上U 下D 左L 右R
void snakemove()
{
    snake* nexthead;
    cantcrosswall();

    nexthead = (snake*)malloc(sizeof(snake));
    if (nexthead == NULL)
    {
        endgamestatus = 3;
        endgame();
    }
    
    if (status == U)
    {
        nexthead->x = head->x;
        nexthead->y = head->y - 1;
        if (nexthead->x == food->x && nexthead->y == food->y)//下一格是食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            score = score + add;
            createfood();
        }
        else                                               //不是食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    else if (status == D)
    {
        nexthead->x = head->x;
        nexthead->y = head->y + 1;
        if (nexthead->x == food->x && nexthead->y == food->y)  //吃到食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            score = score + add;
            createfood();
        }
        else                               //没吃到食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    else if (status == L)
    {
        nexthead->x = head->x - 2;
        nexthead->y = head->y;
        if (nexthead->x == food->x && nexthead->y == food->y)//吃到食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            score = score + add;
            createfood();
        }
        else                                //没吃到食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    else if (status == R)
    {
        nexthead->x = head->x + 2;
        nexthead->y = head->y;
        if (nexthead->x == food->x && nexthead->y == food->y)//吃到食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            score = score + add;
            createfood();
        }
        else                                         //没吃到食物
        {
            nexthead->next = head;
            head = nexthead;
            q = head;
            while (q->next->next != NULL)
            {
                Pos(q->x, q->y);
                printf("■");
                q = q->next;
            }
            Pos(q->next->x, q->next->y);
            printf("  ");
            free(q->next);
            q->next = NULL;
        }
    }
    else
    {
        // 无效的方向，释放内存并退出
        free(nexthead);
        endgamestatus = 3;
        endgame();
    }
    
    if (biteself() == 1)       //判断是否咬到自己
    {
        endgamestatus = 2;
        endgame();
    }
}

//游戏暂停
void pause()
{
    while (1)
    {
        Sleep(300);
        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }

    }
}

//游戏主循环
void gamecircle()
{

    Pos(64, 15);
    printf("不能撞墙壁 不能咬到自己\n");
    Pos(64, 16);
    printf("↑↓←→控制蛇的移动.");
    Pos(64, 17);
    printf("F1 加速 F2 减速\n");
    Pos(64, 18);
    printf("ESC 退出游戏 space暂停游戏.");
    Pos(64, 20);
    printf("%s正在游戏中", current_user.username);
    Pos(64, 21);
    printf("按F5显示游戏用户日志");
    status = R;
    while (1)
    {
        Pos(64, 10);
        printf("得分：%d  ", score);
        Pos(64, 11);
        printf("每个食物得分：%d分", add);
        if (GetAsyncKeyState(VK_UP) && status != D)
        {
            status = U;
        }
        else if (GetAsyncKeyState(VK_DOWN) && status != U)
        {
            status = D;
        }
        else if (GetAsyncKeyState(VK_LEFT) && status != R)
        {
            status = L;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && status != L)
        {
            status = R;
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            pause();
        }
        else if (GetAsyncKeyState(VK_ESCAPE))
        {
            endgamestatus = 3;
            break;
        }
        else if (GetAsyncKeyState(VK_F1))
        {
            if (sleeptime >= 50)
            {
                sleeptime = sleeptime - 30;
                add = add + 2;
            }
        }
        else if (GetAsyncKeyState(VK_F2))
        {
            if (sleeptime < 350)
            {
                sleeptime = sleeptime + 30;
                add = add - 2;
                if (add < 1)
                {
                    add = 1;  //保证最低为1
                }
            }
        }
        else if (GetAsyncKeyState(VK_F5))
        {
            show_game_logs();
        }
        Sleep(sleeptime);
        snakemove();
    }
}

//欢迎界面
void welcometogame()
{
    Pos(40, 12);
    printf("欢迎来到贪吃蛇游戏");
    Pos(40, 25);
    system("pause");
    system("cls");
    Pos(25, 12);
    printf("↑↓←→控制蛇的移动 F1加速 F2减速\n");
    Pos(25, 13);
    printf("吃到食物获得蛇的长度");
    system("pause");
    system("cls");
}

//结束游戏
void endgame()
{
    //计算游戏持续时间并保存日志
    time_t end_time = time(NULL);
    int duration = (int)(end_time - game_start_time);
    save_game_log();

    //释放蛇的内存
    snake* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL; // 避免野指针
    //释放食物内存
    if (food != NULL)
    {
        free(food);
        food = NULL; // 避免野指针
    }

    system("cls");
    Pos(24, 12);
    if (endgamestatus == 1)
    {
        printf("对不起 撞到墙壁了 游戏结束!");
    }
    else if (endgamestatus == 2)
    {
        printf("对不起 咬到自己了 游戏结束!");
    }
    else if (endgamestatus == 3)
    {
        printf("你已经退出游戏");
    }
    Pos(24, 13);
    printf("最终得分%d\n", score);
    
    //游戏结束菜单
    Pos(24, 15);
    printf("1. 重新玩游戏");
    Pos(24, 17);
    printf("2. 查看游戏日志");
    Pos(24, 19);
    printf("3. 换用户登录");
    Pos(24, 21);
    printf("4. 退出游戏");
    Pos(24, 23);
    printf("请选择操作(1-4): ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        //重新玩游戏（需要验证用户名和密码）
        restart_game();
        break;
    case 2:
        //查看游戏日志
        show_game_logs();
        //返回游戏结束菜单
        endgame();
        break;
    case 3:
        //换用户登录
        restart_game();
        break;
    case 4:
        //退出游戏
        exit(0);
        break;
    default:
        //输入错误，重新显示菜单
        Pos(24, 25);
        printf("输入错误，请重新选择！");
        system("pause");
        endgame();
        break;
    }
}

//重新开始游戏（换用户登录）
void restart_game()
{
    //重置游戏参数
    score = 0;
    add = 10;
    status = R;
    sleeptime = 200;
    endgamestatus = 0;
    head = NULL;
    food = NULL;
    
    //重新登录（直接登录，不显示选择菜单）
    system("cls");
    Pos(30, 10);
    printf("=== 用户登录 ===");
    
    char username[50];
    char password[50];
    int login_success = 0;
    
    while (!login_success)
    {
        Pos(30, 12);
        printf("请输入用户名: ");
        scanf("%s", username);
        
        Pos(30, 14);
        printf("请输入密码: ");
        scanf("%s", password);
        
        //检查用户数据
        FILE* fp = fopen("users.txt", "r");
        if (fp == NULL)
        {
            Pos(30, 16);
            printf("用户不存在，请先注册！");
            fclose(fp);
            system("pause");
            register_user();
            login_success = 1;
            continue;
        }
        
        //读取用户数据进行验证
        int id;
        char file_username[50];
        char file_password[50];
        int found = 0;
        int username_exists = 0;
        
        while (fscanf(fp, "%d %s %s", &id, file_username, file_password) != EOF)
        {
            if (strcmp(username, file_username) == 0)
            {
                username_exists = 1;
                if (strcmp(password, file_password) == 0)
                {
                    current_user.id = id;
                    strcpy(current_user.username, file_username);
                    strcpy(current_user.password, file_password);
                    found = 1;
                    break;
                }
            }
        }
        
        fclose(fp);
        
        if (found)
        {
            Pos(30, 16);
            printf("登录成功！欢迎回来，%s", current_user.username);
            system("pause");
            login_success = 1;
        }
        else if (username_exists)
        {
            Pos(30, 16);
            printf("密码错误！");
            system("pause");
        }
        else
        {
            Pos(30, 16);
            printf("用户 %s 未注册，请先注册！", username);
            system("pause");
            register_user();
            login_success = 1;
        }
    }
    
    //开始新游戏
    gamestart();
    gamecircle();
    // 注意：这里不再调用endgame()，避免无限递归
}

//用户注册
void register_user()
{
    system("cls");
    Pos(30, 10);
    printf("=== 用户注册 ===");
    
    int username_exists = 0;
    do
    {
        username_exists = 0;
        Pos(30, 12);
        printf("请输入用户名: ");
        scanf("%s", current_user.username);
        
        //检查用户名是否已存在
        FILE* fp = fopen("users.txt", "r");
        if (fp != NULL)
        {
            int id;
            char file_username[50];
            char file_password[50];
            while (fscanf(fp, "%d %s %s", &id, file_username, file_password) != EOF)
            {
                if (strcmp(current_user.username, file_username) == 0)
                {
                    username_exists = 1;
                    break;
                }
            }
            fclose(fp);
        }
        
        if (username_exists)
        {
            Pos(30, 16);
            printf("用户名已存在，请重新输入！");
            system("pause");
            system("cls");
            Pos(30, 10);
            printf("=== 用户注册 ===");
        }
    } while (username_exists);
    
    Pos(30, 14);
    printf("请输入密码: ");
    scanf("%s", current_user.password);
    
    //生成用户ID（简单实现：基于时间）
    current_user.id = (int)time(NULL) % 10000;
    
    Pos(30, 16);
    printf("注册成功！您的用户ID是: %d", current_user.id);
    
    //保存用户数据
    save_user_data();
    
    Pos(30, 18);
    system("pause");
}

//保存用户数据
void save_user_data()
{
    FILE* fp = fopen("users.txt", "a");
    if (fp != NULL)
    {
        fprintf(fp, "%d %s %s\n", current_user.id, current_user.username, current_user.password);
        fclose(fp);
    }
}

//加载用户数据
void load_user_data()
{
    //这个函数可以用于后续扩展，比如显示所有用户等
}

//用户登录
int login_user()
{
    system("cls");
    Pos(30, 10);
    printf("=== 用户系统 ===");
    Pos(30, 12);
    printf("1. 注册新用户");
    Pos(30, 14);
    printf("2. 用户登录");
    Pos(30, 16);
    printf("请选择操作(1/2): ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1)
    {
        register_user();
        return 1;
    }
    else if (choice == 2)
    {
        system("cls");
        Pos(30, 10);
        printf("=== 用户登录 ===");
        
        char username[50];
        char password[50];
        
        Pos(30, 12);
        printf("请输入用户名: ");
        scanf("%s", username);
        
        Pos(30, 14);
        printf("请输入密码: ");
        scanf("%s", password);
        
        //检查是否是首次注册
        FILE* fp = fopen("users.txt", "r");
        if (fp == NULL)
        {
            //文件不存在，需要注册
            Pos(30, 16);
            printf("用户不存在，请先注册！");
            fclose(fp);
            system("pause");
            register_user();
            return 1;
        }
        
        int id;
        char file_username[50];
        char file_password[50];
        int found = 0;
        int username_exists = 0;
        
        while (fscanf(fp, "%d %s %s", &id, file_username, file_password) != EOF)
        {
            if (strcmp(username, file_username) == 0)
            {
                username_exists = 1;
                if (strcmp(password, file_password) == 0)
                {
                    current_user.id = id;
                    strcpy(current_user.username, file_username);
                    strcpy(current_user.password, file_password);
                    found = 1;
                    break;
                }
            }
        }
        
        fclose(fp);
        
        if (found)
        {
            Pos(30, 16);
            printf("登录成功！欢迎回来，%s", current_user.username);
            system("pause");
            return 1;
        }
        else if (username_exists)
        {
            Pos(30, 16);
            printf("密码错误！");
            system("pause");
            return 0;
        }
        else
        {
            Pos(30, 16);
            printf("用户 %s 未注册，请先注册！", username);
            system("pause");
            register_user();
            return 1;
        }
    }
    else
    {
        Pos(30, 16);
        printf("输入错误，请重新选择！");
        system("pause");
        return 0;
    }
}


void save_game_log()
{
    FILE* fp = fopen("game_logs.txt", "a");
    if (fp != NULL)
    {
        time_t now = time(NULL);
        struct tm* tm_info = localtime(&now);
        char time_str[30];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d_%H:%M:%S", tm_info);
        
        int duration = (int)(now - game_start_time);
        
        fprintf(fp, "%d %s %s %d %d\n", current_user.id, current_user.username, time_str, duration, score);
        fclose(fp);
    }
}

void show_game_logs()
{
    system("cls");
    Pos(10, 5);
    printf("=== 游戏用户日志 ===");
    
    FILE* fp = fopen("game_logs.txt", "r");
    if (fp == NULL)
    {
        Pos(10, 7);
        printf("暂无游戏日志");
        system("pause");
        return;
    }
    
    int user_id, duration, user_score;
    char username[50], start_time[30];
    int line = 7;
    int log_count = 0;
    
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        int result = sscanf(buffer, "%d %s %s %d %d", &user_id, username, start_time, &duration, &user_score);
        if (result == 5)
        {
            Pos(10, line);
            printf("用户ID: %d, 用户名: %s, 开始时间: %s, 持续时间: %d秒, 得分: %d", 
                   user_id, username, start_time, duration, user_score);
            line++;
            log_count++;
            if (line > 25)
            {
                Pos(10, 27);
                printf("按任意键继续...");
                system("pause");
                system("cls");
                Pos(10, 5);
                printf("=== 游戏用户日志 ===");
                line = 7;
            }
        }
    }
    
    if (log_count == 0)
    {
        Pos(10, 7);
        printf("游戏日志文件为空或格式错误");
    }
    
    fclose(fp);
    
    Pos(10, line + 2);
    printf("按任意键返回游戏...");
    system("pause");
    system("cls");
    creatMap();

    q = head;
    while (q != NULL)
    {
        Pos(q->x, q->y);
        printf("■");
        q = q->next;
    }

    if (food != NULL)
    {
        Pos(food->x, food->y);
        printf("●");
    }

    Pos(64, 15);
    printf("不能撞墙壁 不能咬到自己\n");
    Pos(64, 16);
    printf("↑↓←→控制蛇的移动.");
    Pos(64, 17);
    printf("F1 加速 F2 减速\n");
    Pos(64, 18);
    printf("ESC 退出游戏 space暂停游戏.");
    Pos(64, 20);
    printf("%s正在游戏中", current_user.username);
    Pos(64, 21);
    printf("按F5显示游戏用户日志");
    Pos(64, 10);
    printf("得分：%d  ", score);
    Pos(64, 11);
    printf("每个食物得分：%d分", add);
}

void gamestart()
{
    system("mode con cols=100 lines=30");
    welcometogame();
    creatMap();
    initsnake();
    createfood();
    game_start_time = time(NULL);
}

void main()
{
    int login_success = 0;
    while (!login_success)
    {
        login_success = login_user();
    }
    gamestart();
    gamecircle();
    endgame();
    return ;
}