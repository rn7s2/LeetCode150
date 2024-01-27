#include "common.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        int a = cache.count(n - 1) == 0 ? climbStairs(n - 1) : cache[n - 1];
        int b = cache.count(n - 2) == 0 ? climbStairs(n - 2) : cache[n - 2];
        return (cache[n] = a + b);
    }

private:
    map<int, int> cache;

public:
    void run()
    {
        cout << climbStairs(2) << endl;
        cout << climbStairs(3) << endl;
    }
};
