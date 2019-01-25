#include<iostream>
#include<string.h>
using namespace std;
class stack
{
    public:
    int arr[20];
    int top;
    stack()
    {
        top = -1;
    }
    void push(int x)
    {
        arr[++top] = x;
    }
    void pop()
    {
        top--;
    }
    int peek()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
};
bool isOperand(char x)
{
    if(x>='A' && x<='Z')return true;
    if(x>='a' && x<='z')return true;
    if(x>='0' && x<='9')return true;
    return false;
}
bool isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        return true;
}

void evaluatePrefix(string exp)
{
    stack adi;
    int val1,val2,res;
    for(int i=exp.length()-1;i>=0;i--)
    {
        if(isOperand(exp[i]))
        {
            adi.push(exp[i]-'0');
        }
        else if(isOperator(exp[i]))
        {
            val1 = adi.peek();adi.pop();
            val2 = adi.peek();adi.pop();
            switch (exp[i])
            {
             case '+': adi.push(val2 + val1); break;
             case '-': adi.push(val2 - val1); break;
             case '*': adi.push(val2 * val1); break;
             case '/': adi.push(val2/val1);   break;
             case '^': adi.push(val2^val1);   break;
            }
        }
    }
    cout<<adi.peek();
}

int main()
{
    string exp = "+9*26";
    evaluatePrefix(exp);
    return 0;
}
