#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
void insert(node **head,int a)
{
    node* temp=new node;
    temp->data=a;
    temp->next=*head;
    *head=temp;
}
void swapbynode(node **head, int x, int y)
{
   if (x == y) return;
   node *prevX = NULL, *currX = *head;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }
   node *prevY = NULL, *currY = *head;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }

   if (currX == NULL || currY == NULL)
       return;

   if (prevX != NULL)
       prevX->next = currY;
   else
       *head = currY;

   if (prevY != NULL)
       prevY->next = currX;
   else
       *head = currX;

   node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
}
int main()
{
    int n,a,x,y;
    node *head=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        insert(&head,a);
    }
    cin>>x>>y;
    swapbynode(&head,x,y);
    print(head);
}
