#include "common.h"

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        int i, j, len;

        len = s.length();
        for (i = 0; i < len; i++)
        {
            if (isalnum(s[i]))
                str += tolower(s[i]);
        }

        len = str.length();
        i = 0, j = len - 1;
        while (i < j)
        {
            if (str[i] != str[j])
                return false;
            i++, j--;
        }
        return true;
    }
    
    void run()
    {
        cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    }
};
