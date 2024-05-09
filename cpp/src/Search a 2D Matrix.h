#include "common.h"

class Solution
{
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            int v = at(matrix, m);
            if (v == target)
                return true;
            if (v < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }

    int at(vector<vector<int> >& matrix, int i)
    {
        int n = matrix.size(), m = matrix[0].size();
        return matrix[i / m][i % m];
    }

    void run()
    {
        vector<vector<int> > mat;
        vector<int> r1, r2, r3;
        r1.push_back(1);
        r1.push_back(3);
        r1.push_back(5);
        r1.push_back(7);
        r2.push_back(10);
        r2.push_back(11);
        r2.push_back(16);
        r2.push_back(20);
        r3.push_back(23);
        r3.push_back(30);
        r3.push_back(34);
        r3.push_back(60);
        mat.push_back(r1);
        mat.push_back(r2);
        mat.push_back(r3);

        cout << searchMatrix(mat, 3) << endl;
    }
};
