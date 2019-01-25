#include<iostream>
using namespace std;
struct node
{
    node* left;
    node* right;
    int data;
};
node* getdata(int data)
{
    node* newnode=new node;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insertion(node* root,int data)
{
    if(root==NULL)
    {
        root=getdata(data);
    }
    else if(data<=root->data)
    {
        root->left=insertion(root->left,data);
    }
    else
        root->right=insertion(root->right,data);
    return root;
}
bool Search(node* root,int data)
{
    if(root==NULL)
        return false;
    else if(root->data==data)
    {
        return false;
    }
    else if(data<root->data)
        return Search(root->left,data);
    else if(root->data<data)
        return Search(root->right,data);
}

int main()
{
    int n,a,number;
    node* root=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root=insertion(root,a);
    }
    cin>>number;
    if(Search(root,number)==true)
        cout<<"found";

    else
        cout<<"not found";
    return 0;
}
