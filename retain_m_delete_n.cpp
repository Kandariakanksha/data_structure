#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
void push(node** head,int data1)
{
    node* newnode=new node();
    newnode->data=data1;
    newnode->next=*head;
    *head=newnode;
}
void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
}
void skipMdeleteN(node* head,int m,int n)
{
    node* curr=head,*t;
    int count;
    while(curr)
    {
        for(count=1;count<m && curr!=NULL;count++)
        {
            curr=curr->next;
        }
        if(curr==NULL)
            return;
        t=curr->next;
        for(count=1;count<=n && t!=NULL;count++)
        {
            node* temp=t;
            t=t->next;
            delete(temp);
        }
        curr->next=t;
        curr=t;
    }
}
int main()
{
    node* head=NULL;
    int m=2,n=3;
    push(&head,10);
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    print(head);
    skipMdeleteN(head,m,n);
    cout<<"after deletion";
    print(head);
    return 0;
}
