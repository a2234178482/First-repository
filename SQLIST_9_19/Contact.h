#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10 
#define TEL_MAX 20
#define ADDR_MAX 100
//定义联系人数据 结构
//姓名 性别 年龄 电话 地址
typedef struct personInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;


//要用到顺序表相关的方法，对通讯录的操作实际就是对顺序表进行操作
//给顺序表改个名字，叫做通讯录
typedef struct SeqList Contact; //sl
//通讯录相关的方法

//通讯录的初始化
void ContactInit(Contact* con);
//通讯录的销毁
void ContactDesTroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
//通讯录查找
void ContactFind(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);

