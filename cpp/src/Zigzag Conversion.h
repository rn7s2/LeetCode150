#include "common.h"

class Solution
{
public:
    string convert(string s, int numRows)
	{
		int n = s.length();
		int loop = (numRows - 1) << 1;
		
		if (loop <= 1)
			return s;
		
		string ret;
		for (int r = 0; r < numRows; r++)
		{
			for (int i = r; i < n; i += loop)
			{
				ret += s[i];
				
				int offset = i % loop;
				int pos = i + loop - offset - offset;
				if (offset != 0 && offset != numRows - 1 && pos < n)
					ret += s[pos];
			}
		}
		return ret;
    }
	
	void run()
	{
		cout << convert("PAYPALISHIRING", 3).c_str() << endl;
		cout << convert("PAYPALISHIRING", 4).c_str() << endl;
		cout << convert("A", 1).c_str() << endl;
		cout << convert("AB", 1).c_str() << endl;
	}
};
