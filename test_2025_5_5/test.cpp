#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

//vector<vector<int>> compute_transitive_closure(const vector<vector<int>>& adj_matrix) {
//    int n = adj_matrix.size();
//    vector<vector<int>> closure = adj_matrix; 
//    for (int k = 0; k < n; ++k) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
//            }
//        }
//    }
//    return closure;
//}
//
//void print_matrix(const vector<vector<int>>& matrix) {
//    for (const auto& row : matrix) {
//        for (int val : row) {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int n;
//    cout << "输入矩阵大小 (n): ";
//    cin >> n;
//    vector<vector<int>> adj_matrix(n, vector<int>(n));
//    cout << "输入邻接矩阵 (每行" << n << "个整数，0或1):" << endl;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (!(cin >> adj_matrix[i][j])) {
//                cerr << "错误：输入必须为整数。" << endl;
//                return 1;
//            }
//            if (adj_matrix[i][j] != 0 && adj_matrix[i][j] != 1) {
//                cerr << "错误：邻接矩阵元素必须为0或1。" << endl;
//                return 1;
//            }
//        }
//    }
//    vector<vector<int>> closure = compute_transitive_closure(adj_matrix);
//    cout << "\n传递闭包矩阵：" << endl;
//    print_matrix(closure);
//    return 0;
//}
void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 1);
	vector<int> v3(++v2.begin(), --v2.end());
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << "";
	}
	cout << endl;
	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << "";
		it++;
	}
	cout << endl;
	for (auto e : v3)
	{
		cout << e << "";
	}
	cout << endl;
}
void test_vector2()
{
	size_t sz;
	vector<int> v;
	v.reserve(100);
	sz = v.capacity();
	cout << "capacity changed" << sz << "\n";
	cout << "making v grow " << endl;
	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed" << sz << "\n";
		}
	}
}
void test_vector3()
{
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
void test_vector4()
{
	vector<int> v(10, 1);
	v.push_back(2);
	v.insert(v.begin(), 0);
	for (auto e : v)
	{
		cout << e << "  ";
	}
	cout << endl;
	v.insert(v.begin() + 3, 10);
	for (auto e : v)
	{
		cout << e <<  "  ";
	}
	cout << endl;
	vector<int> v1(5, 0);
	for (size_t i = 0; i < 5; i++)
	{
		cin >> v1[i];
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<char> v2;
	string s2;
	vector<int> v3;
}
void test_vector5()
{
	vector<string> v1;
	string s1("xxxxx");
	v1.push_back(s1);
	v1.push_back("yyyyyy");
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	vector<int> v(5, 1);
	vector<vector<int>> vv(10, v);
	vv[2][1] = 2;
}
int main()
{
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector1();
	test_vector5();
}