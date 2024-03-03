#include "common.h"

class Solution
{
public:
    int maxProfit(vector<int>& prices)
	{
		int n = prices.size();

		// TODO
		srand(time(NULL));
		return rand();
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
