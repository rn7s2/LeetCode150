#include "common.h"

class Solution
{
public:
    int trailingZeroes(int n)
    {
        if (n == 0)
            return 0;
        int x = 0;
        for (int i = log(n + 0.5) / log(5); i >= 1; i--)
            x += n / pow(5, i);
        return x;
    }

    /*
    int trailingZeroes(int n)
    {
        if (n == 0)
            return 0;
        int five = 0;
        for (int i = 2; i <= n; i++)
            five += count(i, 5);
        return five;
    }

    int count(int x, int n)
    {
        int cnt = 0;
        while (x % n == 0) {
            ++cnt;
            x /= n;
        }
        return cnt;
    }
    */

    void run()
    {
        cout << trailingZeroes(3) << endl;
        cout << trailingZeroes(5) << endl;
        cout << trailingZeroes(0) << endl;
    }
};
