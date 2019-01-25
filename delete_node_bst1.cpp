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
node* findmin(node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}
node* deletion(node* root,int data)
{
    if(root==NULL)
    {
    return root;
    }
    else if(root->data>data)
    {
        root->left=deletion(root->left,data);
    }
    else if(root->data<data)
    {
       root->right=deletion(root->right,data);
    }
    else
    {
     if(root->left==NULL && root->right==NULL)
     {
         delete(root);
         root=NULL;
     }
     else if(root->right==NULL)
     {
         node* temp=root;
         root=root->left;
         delete temp;
     }
     else if(root->left==NULL)
     {
         node* temp=root;
         root=root->right;
         delete temp;
     }
    else
    {
      node* temp=findmin(root->right);
      root->data=temp->data;
      root->right=deletion(root->right,temp->data);
    }
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
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
      root=deletion(root,number);
      inorder(root);
    return 0;
}
