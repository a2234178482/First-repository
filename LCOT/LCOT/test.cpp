#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void select_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;  
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

vector<int> Random(int n, int v)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % v + 1;
    }
    return arr;
}
vector<int> Copy(const vector<int>& arr)
{
    return vector<int>(arr);
}
bool Same_arr(const vector<int> arr1, const vector<int> arr2)
{
    if (arr1.size() != arr2.size())
        return false;
    for (int i = 0; i < arr1.size(); i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
void Print_arr(const vector<int> arr1)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << "\t";
    }
}
int main()
{
    int N = 500;
    int V = 1000;
    int test = 5000;
    srand(time(nullptr));
    for (int i = 0; i < test; i++)
    {
        vector<int> arr1 = Random(N, V);
        vector<int> arr2 = Copy(arr1);
        vector<int> arr3 = Copy(arr1);
        select_sort(arr2);
        sort(arr3.begin(), arr3.end());
        if (Same_arr(arr2, arr2))
        {
            cout << "原来结果"<<endl;
            Print_arr(arr1);
            cout << "我的结果" << endl;
            Print_arr(arr2);
            cout << "标准结果"<<endl;
            Print_arr(arr3);
        }
        return 1;
        if ((i + 1) % 1000 == 0) {
            cout << "已完成 " << i + 1 << "/" << test << " 次测试..." << endl;
        }
    }
}