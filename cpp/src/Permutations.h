#include "common.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(nums, path, ret);
        return ret;
    }

    map<int, bool> vis;

    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i])
                continue;
            path.push_back(nums[i]);
            vis[i] = true;
            dfs(nums, path, res);
            vis[i] = false;
            path.pop_back();
        }
    }

    void run() {
        vector<int> nums = { 1, 2, 3 };
        auto res = permute(nums);
        dump_2d(res);
    }
};
