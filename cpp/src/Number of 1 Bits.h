#include "common.h"

class Solution {
public:
    int hammingWeight(int n)
    {
        int cnt = 0;
        while (n > 0) {
            if (n & 1)
                ++cnt;
            n >>= 1;
        }
        return cnt;
    }

    void run()
    {
        cout << hammingWeight(11) << endl;
        cout << hammingWeight(128) << endl;
    }
};
