#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

struct Student {
    int age;
    string name;

    Student(int a, const string& b) : age(a), name(b) {}
};

int main() {
    // Integer、Long、Double、Float
    // Byte、Short、Character、Boolean
    // string 等都有这个特征
    string* str1 = new string("Hello");
    string* str2 = new string("Hello");

    // false，因为不同的内存地址
    cout << (str1 == str2) << endl;
    // true，因为它们的值是相同的
    cout << (*str1 == *str2) << endl;

    unordered_set<string> set;
    set.insert(*str1);
    cout << set.count("Hello") << endl;      // contains
    cout << set.count(*str2) << endl;        // contains
    set.insert(*str2);
    cout << set.size() << endl;
    set.erase(*str1);
    set.clear();
    cout << set.empty() << endl;

    cout << "===========" << endl;

    unordered_map<string, string> map1;
    map1[*str1] = "World";
    cout << (map1.find("Hello") != map1.end()) << endl;   // containsKey
    cout << (map1.find(*str2) != map1.end()) << endl;     // containsKey
    cout << map1[*str2] << endl;                          // get
    cout << (map1.find("你好") == map1.end()) << endl;    // get returns null equivalent
    map1.erase("Hello");
    cout << map1.size() << endl;
    map1.clear();
    cout << map1.empty() << endl;

    delete str1;
    delete str2;

    cout << "===========" << endl;

    // 一般在笔试中，未必需要申请哈希表
    unordered_map<int, int> map2;
    map2[56] = 7285;
    map2[34] = 3671263;
    map2[17] = 716311;
    map2[24] = 1263161;

    // 上面的 map2 行为，可以被如下数组的行为替代
    int arr[101] = { 0 };  // 假设最大 key 不超过 100
    arr[56] = 7285;
    arr[34] = 3671263;
    arr[17] = 716311;
    arr[24] = 1263161;
    // 哈希表的增、删、改、查，都可以被数组替代，前提是 key 的范围是固定的、可控的
    cout << "在笔试场合中哈希表往往会被数组替代" << endl;

    cout << "===========" << endl;

    Student s1(17, "张三");
    Student s2(17, "张三");

    // 使用指针作为 key，因为 Student 没有定义哈希函数
    // 这样可以模拟 Java 中基于内存地址的比较
    unordered_map<Student*, string> map3;
    map3[&s1] = "这是张三";
    cout << (map3.find(&s1) != map3.end()) << endl;   // containsKey
    cout << (map3.find(&s2) != map3.end()) << endl;   // containsKey
    map3[&s2] = "这是另一个张三";
    cout << map3.size() << endl;
    cout << map3[&s1] << endl;                       // get
    cout << map3[&s2] << endl;                       // get

    return 0;
}
