#include<iostream>
#include<queue>
using namespace std;
struct node
{
    node* right;
    node* left;
    int data;
};
node* getdata(int a)
{
    node* newnode=new node();
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->data=a;
    return newnode;
}
node* insertion(node* root,int a)
{
    if(root==NULL)
    {
        root=getdata(a);
    }
      else if(a<=root->data)
    {
        root->left=insertion(root->left,a);
    }
    else
        root->right=insertion(root->right,a);
    return root;
}
void depthfirst(node* root)
{
    if(root==NULL)
       return;
    queue<node* >q;
    q.push(root);
    while(!q.empty())
    {
        node* current=q.front();
        cout<<current->data;
        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
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
    depthfirst(root);
    return 0;
}
