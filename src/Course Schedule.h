#include "common.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        auto in = vector<int>(numCourses, 0);
        auto vis = vector<bool>(numCourses, false);
        auto g = vector<vector<int>>(numCourses, vector<int>());

        for (auto& e : prerequisites) {
            int u = e[1], v = e[0];
            ++in[v];
            g[u].push_back(v);
        }

        int removeCnt = 0;
        while (true) {
            bool removed = false;
            for (int i = 0; i < numCourses; i++) {
                if (!vis[i] && in[i] == 0) {
                    for (auto v : g[i]) {
                        --in[v];
                    }
                    removed = true;
                    vis[i] = true;
                    ++removeCnt;
                }
            }

            if (!removed) {
                break;
            }
        }

        return removeCnt == numCourses;
    }

    void run()
    {
        int numCourses = 2;
        auto prerequisites = vector<vector<int>>{{1, 0}};
        cout << canFinish(numCourses, prerequisites) << endl;
    }
};
