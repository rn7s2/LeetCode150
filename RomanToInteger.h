#include "common.h"

class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.length(), ret = 0;
        
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = s[i];
            switch (ch)
            {
            case 'I': {
                bool sub = (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X'));
                ret += (sub ? -1 : 1);
                break;
                      }
            case 'V':
                ret += 5;
                break;
            case 'X': {
                bool sub = (i + 1 < n && (s[i + 1] == 'L' || s[i + 1] == 'C'));
                ret += (sub ? -10 : 10);
                break;
                      }
            case 'L':
                ret += 50;
                break;
            case 'C': {
                bool sub = (i + 1 < n && (s[i + 1] == 'D' || s[i + 1] == 'M'));
                ret += (sub ? -100 : 100);
                break;
                      }
            case 'D':
                ret += 500;
                break;
            case 'M':
                ret += 1000;
                break;
            default:
                break;
            }
        }
        
        return ret;
    }
    
    void run()
    {
        cout << romanToInt("III") << endl;
        cout << romanToInt("LVIII") << endl;
        cout << romanToInt("MCMXCIV") << endl;
    }
};
