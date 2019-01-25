#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void addfirst(node** last,int a)
{
    node* temp=new node;
    temp->data=a;
    temp->next=NULL;
     *last = temp;
}
void insertion(node** last,int a)
{
    if(*last==NULL)
    {
        addfirst(&*last,a);
        return;
    }
    node* temp=new node;
    temp->data=a;
    temp->next = (*last)->next;
    (*last)->next=temp;
    *last=temp;
}
void insertionatend(node** last,int a)
{
    node* temp=new node;
    temp->data=a;
    temp->next=(*last)->next;
    (*last)->next=temp;
    *last=temp;
}
void between(node** last,int a,int pos)
{
    if(*last==NULL)
        return;
    node* temp=*last;
    while(temp->data!=pos)
    {
        temp=temp->next;
    }
    node* temp2=new node;
    temp2->data=a;
    temp2->next=NULL;
    temp2->next=temp->next;
    temp->next=temp2;
}
void traverse(node* last)
{
    node* temp=last;
     do
        {
            cout<<temp->data;
            temp = temp->next;
        }
        while (temp != last);
}
int main()
{
    node *last=NULL;
    int n,a,element,pos,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        insertion(&last,a);
    }
    traverse(last);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertionatend(&last,x);
    }
    traverse(last);
    cout<<endl;
    cin>>element>>pos;
     between(&last,element,pos);
      traverse(last);
      cout<<endl;
return 0;
}
