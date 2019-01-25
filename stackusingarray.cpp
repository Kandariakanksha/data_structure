#include<iostream>
# define MAXSIZE 101
using namespace std;
int a[MAXSIZE];
int top=-1;
void push(int data)
{
    a[++top]=data;
}
void pop()
{
    top=top-1;
}
bool IsEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    push(2);
    push(3);
    pop();
    if(IsEmpty())
    {
        cout<<"empty";
    }
    else
    {
        cout<<"not empty";
    }
    return 0;
}
