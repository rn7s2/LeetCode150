#include "common.h"

const int dx[] = { -1, 0,  0, 1 };
const int dy[] = {  0, 1, -1, 0 };

class Solution {
public:
    set<pair<int, int>> vis;

    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto point = make_pair(i, j);
                vis.insert(point);
                if (board[i][j] == word[0] && dfs(board, word, i, j, 1)) {
                    cout << i << " " << j << endl;
                    return true;
                }
                vis.erase(point);
            }
        }
        return false;
    }

    bool pass_flag = false;

    bool dfs(vector<vector<char>>& board, const string& word, int x, int y, int cnt)
    {
        if (pass_flag)
            return false;

        int n = board.size(), m = board[0].size();
        if (cnt == word.size()) {
            pass_flag = true;
            return true;
        } else {
            bool exist = false;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m)
                    continue;
                auto point = make_pair(a, b);
                if (!vis.count(point) && board[a][b] == word[cnt]) {
                    vis.insert(point);
                    exist = exist || dfs(board, word, a, b, cnt + 1);
                    vis.erase(point);
                }
            }
            return exist;
        }
    }

    void run()
    {
        vector<vector<char>> board{ {{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E' }} };
        cout << exist(board, "ABCCED") << endl;
    }
};
