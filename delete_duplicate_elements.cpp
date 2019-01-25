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
void sort(node **head)
{
   node *i,*j;
   int temp;
   for(i=*head;i!=NULL;i=i->next)
   {
       for(j=i->next;j!=NULL;j=j->next)
       {
           if((i->data)>(j->data))
           {
               temp=i->data;
               i->data=j->data;
               j->data=temp;
           }
       }
   }
}
void duplicate(node **head)
{
   node *current=*head;
   node *next_next;
   if(current==NULL)
    return;
   while(current->next!=NULL)
   {
       if(current->data==current->next->data)
       {
           next_next=current->next->next;
           delete(current->next);
           current->next=next_next;
       }
       else
        current=current->next;
   }

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
    sort(&head);
  duplicate(&head);
    print(head);
}
