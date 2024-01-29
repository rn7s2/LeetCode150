#include "common.h"

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        nums1.resize(m + n);
        
        int p = m + n - 1, i = m - 1, j = n - 1;
        while (p >= 0)
        {
            while (i >= 0 && j >= 0) {
                if (nums1[i] >= nums2[j])
                    nums1[p--] = nums1[i--];
                else
                    nums1[p--] = nums2[j--];
            }
            while (i >= 0)
                nums1[p--] = nums1[i--];
            while (j >= 0)
                nums1[p--] = nums2[j--];
        }
    }
    
    void run()
    {
        vector<int> n1;
        n1.push_back(1);
        n1.push_back(2);
        n1.push_back(3);
        n1.push_back(0);
        n1.push_back(0);
        n1.push_back(0);
        
        vector<int> n2;
        n2.push_back(2);
        n2.push_back(5);
        n2.push_back(6);
        
        merge(n1, 3, n2, 3);
        
        for (int i = 0; i < n1.size(); i++) {
            cout << n1[i] << " ";
        }
        cout << endl;
    }
};
