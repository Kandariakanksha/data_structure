#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insert(node **head,int x)
{
    node *temp=new node;
    temp->data=x;
    temp->next=*head;
    *head=temp;
}
void reverse(node **head)
{
   node *current=*head;
   node *prev=NULL;
   node *next1;
   while(current!=NULL)
   {
       next1=current->next;
       current->next=prev;
       prev=current;
       current=next1;
   }
   *head=prev;
}
void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
}
int main()
{
    int n,x;
    cin>>n;
    node *head=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(&head,x);
    }
    reverse(&head);
    print(head);
}
