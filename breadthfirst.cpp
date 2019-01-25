#include<iostream>
using namespace std;
struct node
{
node* right=NULL;
node* left=NULL;
int data;
};
node* getdata(int data)
{
    node* newnode=new node;
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
node* insertion(node* root,int data)
{
    if(root==NULL)
    {
        root=getdata(data);
    }
    else if(data<root->data)
    {
        root->right=insertion(root->left,data);
    }
    else
    {
        root->right=insertion(root->right,data);
    }
    return root;
}
void prefix(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data;
    prefix(root->left);
    prefix(root->right);
}
void infix(node* root)
{
    if(root==NULL)
        return;
    infix(root->left);
    cout<<root->data;
    infix(root->right);
}
void postfix(node* root)
{
    if(root==NULL)
        return;
    postfix(root->left);
    postfix(root->right);
    cout<<root->data;
}
int main()
{
    int n,a;
    node* root=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root=insertion(root,a);
    }
    prefix(root);
    cout<<endl;
    infix(root);
    cout<<endl;
    postfix(root);
    cout<<endl;
}
