#include "common.h"

class Solution
{
public:
    int maxProfit(vector<int>& prices)
	{
		int n = prices.size();
		int postfix = 0;
		int ret = 0;

		for (int i = n - 2; i >= 0; i--) {
			if (postfix < prices[i + 1])
				postfix = prices[i + 1];

			ret = max(ret, postfix - prices[i]);
		}

		return ret;
    }

	void run()
	{
		vector<int> v;
		v.push_back(7);
		v.push_back(1);
		v.push_back(5);
		v.push_back(3);
		v.push_back(6);
		v.push_back(4);

		cout << maxProfit(v) << endl;
	}
};
