#include "common.h"

class Solution
{
public:
    int minimumTotal(vector<vector<int> >& triangle)
    {
        int n = triangle.size();
        if (n == 0)
            return 0;
        vector<vector<int> > dp(n);
        
        dp[0].push_back(triangle[0][0]);
        for (int i = 1; i < n; i++)
        {
            dp[i].push_back(dp[i - 1][0] + triangle[i][0]);
            for (int j = 1; j < i; j++)
                dp[i].push_back(min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]);
            dp[i].push_back(dp[i - 1].back() + triangle[i].back());
        }
        
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
    
    void run()
    {
        vector<vector<int> > triangle;
        vector<int> line1;
        line1.push_back(2);
        triangle.push_back(line1);
        
        vector<int> line2;
        line2.push_back(3);
        line2.push_back(4);
        triangle.push_back(line2);
        
        vector<int> line3;
        line3.push_back(6);
        line3.push_back(5);
        line3.push_back(7);
        triangle.push_back(line3);
        
        vector<int> line4;
        line4.push_back(4);
        line4.push_back(1);
        line4.push_back(8);
        line4.push_back(3);
        triangle.push_back(line4);
        
        cout << minimumTotal(triangle) << endl;
    }
};
