#include "common.h"

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        int n = profits.size();
        vector<int> ids = vector<int>(n, 0);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int a, int b) { return capital[a] < capital[b]; });

        priority_queue<int> P;

        int p = 0;
        while (k--) {
            while (p < n && capital[ids[p]] <= w) {
                P.push(profits[ids[p++]]);
            }

            if (P.empty())
                break;
            w += P.top();
            P.pop();
        }

        return w;
    }

    void run()
    {
        case0();
        case1();
        case2();
    }

    void case0()
    {
        vector<int> profits;
        profits.push_back(1);
        profits.push_back(2);
        profits.push_back(3);

        vector<int> capital;
        capital.push_back(0);
        capital.push_back(1);
        capital.push_back(1);

        cout << findMaximizedCapital(2, 0, profits, capital) << endl;
    }

    void case1()
    {
        vector<int> profits;
        profits.push_back(1);
        profits.push_back(2);
        profits.push_back(3);

        vector<int> capital;
        capital.push_back(0);
        capital.push_back(1);
        capital.push_back(2);

        cout << findMaximizedCapital(3, 0, profits, capital) << endl;
    }

    void case2()
    {
        vector<int> profits{ 1,2,3 };
        vector<int> capital{ 1,1,2 };

        cout << findMaximizedCapital(1, 2, profits, capital) << endl;
    }
};
