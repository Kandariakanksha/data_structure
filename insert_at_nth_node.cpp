#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node * insertit(node* head,int a)
{
    node *temp=new node;
    temp->data=a;
    temp->next=head;
    head=temp;
    return head;
}
void insert(node **head,int x,int pos)
{
   node *temp=new node;
   temp->data=x;
   temp->next=NULL;
   if(pos==1)
   {
       temp->next=*head;
       *head=temp;
       return;
   }
   node *temp2=*head;
   for(int i=0;i<pos-2;i++)
   {
       temp2=temp2->next;
   }
   temp->next=temp2->next;
   temp2->next=temp;
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
    int pos,i,x,n,a;
    node *head=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
         cin>>a;
        head=insertit(head,a);
    }
    cin>>x;
    cin>>pos;
    insert(&head,x,pos);
    print(head);
    return 0;
}

