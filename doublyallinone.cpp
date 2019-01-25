#include<iostream>
using namespace std;
struct node
{
    node *prev;
    node *next;
    int data;
};
node *head;
node* getnewnode(int x)
{
    node* newnode=new node;
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insertatbegin(int x)
{
    node* newnode=getnewnode(x);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
void insertatend(int x)
{
    node* newnode=getnewnode(x);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
void reverseprint()
{
    node* temp = head;
	if(temp == NULL) return;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	while(temp != NULL) {
		cout<<temp->data;
		temp = temp->prev;
	}
}
int main()
{
    int n,a,x;
    head=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertatbegin(x);
    }
    print();
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        insertatend(a);
    }
     print();
     cout<<endl;
     reverseprint();
     cout<<endl;
    return 0;
}
