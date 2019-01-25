#include<iostream>
#include<math.h>
using namespace std;
#include<stack>
#include<string>
struct node
{
    int data;
    node* next;
};
node* head=NULL;
void reverseit(char *c,int n)
{
    if(head==NULL)
    {
        return;
    }
    stack<struct node*>s;
    node* temp=head;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    temp=s.top();
    head=temp;
    s.pop();
    while(!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    char c[100];
    cin>>c;
    reverseit(c,strlen(c));
    return 0;
}
