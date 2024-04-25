#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

// define missing functions for VC6
#if (_MSC_VER == 1200)

template <typename T>
const T& max(const T& a, const T& b)
{
    return (a < b) ? b : a;
}

#else

#include <numeric>

#endif

using namespace std;

template <typename T>
void dump(const vector<T>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}

template <typename T>
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
