#include "common.h"

bool shorter(string a, string b)
{
	return a.length() <= b.length();
}

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		int n = strs.size();
		int m = min_element(strs.begin(), strs.end(), shorter)->length();
		string ret = "";
		
		for (int i = 0; i < m; i++)
		{
			char ch = strs[0][i];
			for (int j = 1; j < n; j++)
			{
				if (strs[j][i] != ch)
					return ret;
			}
			ret += ch;
		}
		
		return ret;
    }
	
	
	void run()
	{
		vector<string> strs;
		strs.push_back("flower");
		strs.push_back("flow");
		strs.push_back("flight");

		cout << longestCommonPrefix(strs).c_str() << endl;
	}
};
