#include<iostream>
using namespace std;
struct node
{
node* next;
int data;
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
node* rearrange(node*head)
{
   if(head==NULL)
   {
       return NULL;
   }
   node* odd=head;
   node* even=head;
   node* evenfirst=even;
   while(1)
   {
       if(!odd || !even || !(even->next))
       {
           odd->next=evenfirst;
           break;
       }
       odd->next=even->next;
       odd=even->next;
       if(odd->next==NULL)
       {
           even->next=NULL;
           odd->next=evenfirst;
           break;
       }
       even->next=odd->next;
       even=odd->next;
   }
    return head;
}
int main()
{
    node* head=NULL;
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
    head=rearrange(head);
    print(head);
    return 0;
}
