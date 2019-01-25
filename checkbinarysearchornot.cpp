#include<iostream>
using namespace std;
struct node
{
    node* right;
    node* left;
    int data;
};
node* getdata(int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->right=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insertion(node* root,int data)
{
    if(root==NULL)
        root=getdata(data);
    else if(root->data>data)
    {
        root->left=insertion(root->left,data);
    }
    else
        root->right=insertion(root->right,data);
    return root;
}
bool isutilbinary(node* root,int min_value,int max_value)
{
    if(root==NULL)
        return true;
    if((root->data<max_value&& root->data>min_value)&& isutilbinary(root->left,min_value,root->data)&& isutilbinary(root->right,root->data,max_value))
       {
           return true;
       }
       else
        return false;
}
bool isbinary(node* root)
{
    return isutilbinary(root,INT_MIN,INT_MAX);
}
int main()
{
    node* root=NULL;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root=insertion(root,a);
    }
    if(isbinary(root))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    return 0;
}
