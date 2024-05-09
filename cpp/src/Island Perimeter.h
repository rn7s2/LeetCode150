#include "common.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
		int n = grid.size(), m = grid[0].size();
		int ret = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j])
					ret += cellWaterCount(grid, i, j);
			}
		}

		return ret;
    }

	int cellWaterCount(vector<vector<int> >& grid, int i, int j) {
		int n = grid.size(), m = grid[0].size();
		int cnt = 0;

		int dx[] = {-1, 0,  0, 1};
		int dy[] = { 0, 1, -1, 0};
		for (int d = 0; d < 4; d++) {
			int x = i + dx[d];
			int y = j + dy[d];

			if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
				++cnt;
			}
		}

		return cnt;
	}

	void run() {
		vector<int> r1;
		r1.push_back(0);
		r1.push_back(1);
		r1.push_back(0);
		r1.push_back(0);

		vector<int> r2;
		r2.push_back(1);
		r2.push_back(1);
		r2.push_back(1);
		r2.push_back(0);

		vector<int> r3;
		r3.push_back(0);
		r3.push_back(1);
		r3.push_back(0);
		r3.push_back(0);

		vector<int> r4;
		r4.push_back(1);
		r4.push_back(1);
		r4.push_back(0);
		r4.push_back(0);

		vector<vector<int> > g;
		g.push_back(r1);
		g.push_back(r2);
		g.push_back(r3);
		g.push_back(r4);

		cout << islandPerimeter(g) << endl;
	}
};
