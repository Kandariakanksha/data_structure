#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* top=NULL;
void push(int x)
{
    node* temp=new node();
    temp->data=x;
    temp->next=top;
    top=temp;
}
void pop()
{
    node* temp;
    if(top==NULL)
    {
        return;
    }
    temp=top;
    top=top->next;
    delete(temp);
}
bool IsEmpty()
{
    if(top==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void print()
{
while(top!=NULL)
{
    cout<<top->data;
    top=top->next;
}
}
int main()
{
    push(2);
    push(4);
    push(6);
    pop();
    pop();
    if(IsEmpty())
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    print();
    return 0;
}
