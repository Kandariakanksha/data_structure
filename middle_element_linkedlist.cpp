#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* push(node* head,int a)
{
    node *temp=new node();
    temp->data=a;
    temp->next=head;
    head=temp;
}
void printmiddle(node* head)
{
    node* slow_ptr = head;
    node* fast_ptr = head;
    if(head!=NULL)
    {
        while(fast_ptr!=NULL && fast_ptr->next!=NULL)
        {
            fast_ptr=fast_ptr->next->next;
            slow_ptr=slow_ptr->next;
        }
         cout<<slow_ptr->data;
    }

}
int main()
{
    node* head=NULL;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
       head= push(head,a);
    }
    printmiddle(head);
    return 0;
}
