#include "common.h"

class MinStack
{
public:
    MinStack()
	{
		min.push(INT_MAX);
	}
    
    void push(int val)
	{
		if (val <= min.top())
			min.push(val);
		s.push(val);
    }
    
    void pop()
	{
		if (s.top() == min.top())
			min.pop();
		s.pop();
    }
    
    int top()
	{
		return s.top();
    }
    
    int getMin()
	{
		return min.top();
    }
	
private:
	stack<int> s, min;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

class Solution
{
public:
	void run()
	{
		MinStack* obj = new MinStack();
		obj->push(-2);
		obj->push(0);
		obj->push(-3);
		cout << obj->getMin() << endl;
		obj->pop();
		cout << obj->top() << endl;
		cout << obj->getMin() << endl;
		delete obj;
	}
};
