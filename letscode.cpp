#include<iostream>
using namespace std;
struct node
{
    node* left;
    node* right;
    int data;
};
node* getdata(int a)
{
    node *newnode=new node();
    newnode->data=a;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insertion(node* root,int a)
{
    if(root==NULL)
    {
        root=getdata(a);
        return root;
    }
    else if(a>root->data)
    {
        root->right=insertion(root->right,a);
    }
    else
    {
        root->left=insertion(root->left,a);
    }
    return root;
}
node* findmin(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node* deletion(node* root,int b)
{
    if(root==NULL)
    {
        cout<<"not possible to delete";
        return root;
    }
    else if(b>root->data)
    {
       root->right= deletion(root->right,b);
    }
    else if(b<root->data)
    {
    root->left=deletion(root->left,b);
    }
    else
    {
    if(root->left==NULL && root->right==NULL)
    {
        delete(root);
        root=NULL;
    }
    else if(root->left==NULL)
    {
        node* temp=root;
        root=root->right;
        delete temp;
    }
    else if(root->right==NULL)
    {
        node* temp=root;
        root=root->left;
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
void infix(node* root)
{
    if(root==NULL)
        return;
    infix(root->left);
    cout<<root->data<<endl;
    infix(root->right);
}
int main()
{
    node* root=NULL;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root=insertion(root,a);
    }
   cin>>b;
    root=deletion(root,b);
    infix(root);
    return 0;
}
