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
/*void deleteat(node **head,int pos)
{
    node *temp2=*head;
    node *temp=new node;
    node *temp3=*head;

    for(int i=0;i<pos-1;i++)
    {
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    for(int i=0;i<pos-2;i++)
    {
        temp3=temp3->next;
    }
    temp3->next=temp2->next;

}*/
void deleteat(node **head,int pos)
{
    node *temp1=*head;
    for(int i=0;i<pos-2;i++)
    {
        temp1=temp1->next;
    }
    node *temp2=temp1->next;
    temp1->next=temp2->next;
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
    int n,x,pos;
    node *head=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(&head,x);
    }
    cin>>pos;
    deleteat(&head,pos);
    print(head);
    return 0;
}
