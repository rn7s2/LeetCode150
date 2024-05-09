#include "common.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ret = left, cnt = 0;
        while (left > 0) {
            if (left & 1) {
                ret &= ~(1 << cnt);
                ret |= ((left == right) << cnt);
            }

            left >>= 1;
            right >>= 1;
            ++cnt;
        }
        return ret;
    }

    void run()
    {
        cout << rangeBitwiseAnd(5, 7) << endl;
        cout << rangeBitwiseAnd(0, 0) << endl;
        cout << rangeBitwiseAnd(1, 2147483647) << endl;
    }
};
