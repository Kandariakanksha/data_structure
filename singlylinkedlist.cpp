#include<iostream>
using namespace std;
struct node
{
    node* prev;
    node* next;
    int data;
};
class trees
{
    public:
    struct node *insertion(struct node *, int);
    int frequency(struct node *, int);
};
struct node* trees::insertion(struct node* start,int num)
{
    node* temp=new node();
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;
    if(start==NULL)
    {
      start=temp;
      temp->next=NULL;
    }
    else{
        node* ptr=start;
        while(ptr->next!=NULL)
        {
          ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
    return start;
}
int trees::frequency(struct node* start,int freq)
{
    struct node* temp=start;
    int count=0;
    while(temp!=NULL)
    {
        if(temp->data==freq)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;

}
int main()
{
    trees t;
    struct node *start=NULL;
    int size,c,val,num,fren;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>num;
        start=t.insertion(start,num);
    }
    cin>>fren;
    cout<<"Number of times "<<fren<<" comes is: "<< t.frequency(start, fren);
}
