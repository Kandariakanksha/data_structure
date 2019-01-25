#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insertatend(node **head,int x)
{
   node *temp=new node;
   temp->data=x;
   temp->next=NULL;
   if(*head==NULL)
   {
      temp->next=*head;
      *head=temp;
      return;
   }
   node *temp2=*head;
   while(temp2->next!=NULL)
   {
       temp2=temp2->next;
   }
   temp2->next=temp;
}
void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
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
        insertatend(&head,x);
    }
    print(head);
    return 0;
}
