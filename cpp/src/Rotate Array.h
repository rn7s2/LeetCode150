#include "common.h"

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
	{
		int n = nums.size();
        k %= n;

		rotate(nums, 0, n - 1);
		rotate(nums, 0, k - 1);
		rotate(nums, k, n - 1);
    }

	void rotate(vector<int>& nums, int l, int r)
	{
		while (l < r)
			swap(nums[l++], nums[r--]);
	}

	void run()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		rotate(v, 3);
		dump(v);
	}
};
