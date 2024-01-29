#include "common.h"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		int end_idx = find(wordList, endWord);
		if (end_idx < 0)
			return 0;

		int n = wordList.size();
		vector<vector<int> > g(n + 1);

		// we can build graph here, or construct next node during bfs (quicker)
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (adjacent(wordList[i], wordList[j]))
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (adjacent(beginWord, wordList[j]))
				g[n].push_back(j);
		}

		vector<int> dis(n + 1, INT_MAX);
		queue<pair<int, int> > q;

		dis[n] = 0;
		q.push(make_pair(n, 1));
		while (!q.empty())
		{
			pair<int, int> tmp = q.front();
			int u = tmp.first, step = tmp.second;
			q.pop();

			if (u == end_idx)
				return step;

			for (int i = g[u].size() - 1; i >= 0; i--)
			{
				int v = g[u][i];
				int d = dis[u] + 1;
				if (d < dis[v])
				{
					dis[v] = d;
					q.push(make_pair(v, step + 1));
				}
			}
		}
		return 0;
    }

	int find(const vector<string>& list, const string& s)
	{
		for (int i = list.size() - 1; i >= 0; i--)
		{
			if (list[i].compare(s) == 0)
				return i;
		}
		return -1;
	}

	bool adjacent(const string& a, const string& b)
	{
		int n = a.length();
		int m = b.length();
		if (n != m)
			return false;

		int diff = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
				++diff;
			if (diff > 1)
				return false;
		}
		return true;
	}

	void run()
	{
		vector<string> list;

		list.push_back("hot");
		list.push_back("dot");
		list.push_back("dog");
		list.push_back("lot");
		list.push_back("log");
		list.push_back("cog");
		cout << ladderLength("hit", "cog", list) << endl;

		list.clear();
		list.push_back("hot");
		list.push_back("dot");
		cout << ladderLength("hot", "dog", list) << endl;
	}
};
