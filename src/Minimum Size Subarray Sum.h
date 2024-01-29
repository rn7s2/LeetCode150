#include "common.h"

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int last = 0, now = -1, sum = 0;
        
        do
        {
            sum += nums[++now];
            while (now + 1 < n && sum < target)
                sum += nums[++now];
            while (sum - nums[last] >= target)
                sum -= nums[last++];
            if (sum < target)
                return 0;
            ans = min(ans, now - last + 1);
        } while (now + 1 < n);
        
        return ans;
    }
    
    void run()
    {
        vector<int> arr;
        
        arr.clear();
        arr.push_back(2);
        arr.push_back(3);
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(4);
        arr.push_back(3);
        cout << minSubArrayLen(7, arr) << endl;
        
        arr.clear();
        arr.push_back(1);
        arr.push_back(4);
        arr.push_back(4);
        cout << minSubArrayLen(4, arr) << endl;
        
        arr.clear();
        arr.push_back(1);
        arr.push_back(1);
        arr.push_back(1);
        arr.push_back(1);
        arr.push_back(1);
        arr.push_back(1);
        arr.push_back(1);
        arr.push_back(1);
        cout << minSubArrayLen(11, arr) << endl;
    }
};
