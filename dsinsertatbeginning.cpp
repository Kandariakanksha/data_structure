#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node * insert(node* head,int a)
{
    node *temp=new node;
    temp->data=a;
    temp->next=head;
    head=temp;
    return head;
}
void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"";
        head=head->next;
    }
}
int main()
{
    int n,x;
    node *head=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head=insert(head,x);
    }
    print(head);
    return 0;
}
