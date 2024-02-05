#include "common.h"

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (tokens[i].compare("+") == 0) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a + b);
            } else if (tokens[i].compare("-") == 0) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a - b);
            } else if (tokens[i].compare("*") == 0) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a * b);
            } else if (tokens[i].compare("/") == 0) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(a / b);
            } else {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        
        return s.top();
    }
    
    void run()
    {
        vector<string> tokens;
        tokens.push_back("2");
        tokens.push_back("1");
        tokens.push_back("+");
        tokens.push_back("3");
        tokens.push_back("*");
        cout << evalRPN(tokens) << endl;
    }
};
