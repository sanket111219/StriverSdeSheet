#include<stack>
using namespace std;

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<int> s;
    int n = expression.length();
    for(int i = 0; i < n; i++)
    {
        if(s.empty())
           s.push(expression[i]);
        
        else if(s.top() == '{' && expression[i] == '}' || s.top() == '(' && expression[i] == ')' || s.top() == '['                                 && expression[i] == ']')
            s.pop();
        else
            s.push(expression[i]);
            
    }
    if(s.empty())
        return true;
    else
        return false;
}