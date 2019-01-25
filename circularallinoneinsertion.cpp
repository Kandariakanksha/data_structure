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
    last=temp;
}
void insertion(node** last,int a)
{
    if(last==NULL)
    {
        addfirst(&last,a)//how to store data and stor ethe value in the same last pointer to pointer variable
        return;
    }
    node* temp=new node;
    temp->data=a;
    temp->next=*last->next;//what is this error
    *last->next=temp;
    *last=temp;
}
void insertionatend(node** last,int a)
{
    node* temp=new node;
    temp->data=a;
    temp->next=*last->next;
    *last->next=temp;
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
    //tell me the condn????
    //i remember something like rear and front what was it???
    //i dont remember exactly
   // while(temp!=)
}
int main()
{
    node *last=NULL;
    int n,a;
    addfirst(last,a);
    traverse(last);
return 0;
}
