#include <algorithm>
#include <iostream>
#include <map>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

template<typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
void dump(const vector<T>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}

template<typename T>
void dump_2d(const vector<vector<T> >& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		const vector<T>& r = v[i];
		int m = r.size();
		for (int j = 0; j < m; j++)
			cout << r[j] << " ";
		cout << endl;
	}
}
