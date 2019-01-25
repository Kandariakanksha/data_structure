#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
class BST
{
    public:
    struct Node * insert(struct Node *, int);
    void Search(struct Node *, int);
};
Node* newnode(int num)
{
    Node* newdata=new Node;
    newdata->data=num;
    newdata->right=NULL;
    newdata->left=NULL;
    return newdata;
}
struct Node* BST::insert(struct Node* root,int num)
{
    if(root==NULL)
    {
       root= newnode(num);
    }
    else{
        if(num<=root->data)
        {
            root->left=insert(root->left,num);
        }
        else{
            root->right=insert(root->right,num);
        }
    }
    return root;
};
void BST::Search(Node* root,int num)
{
    if(root==NULL)
    {
        cout<<"Not found";
        return;
    }
    else
    {
    if(num==root->data)
    {
        cout<<"found";
    }
    else if(num < root->data)
    {
        Search(root->left,num);
    }
    else
    {
        Search(root->right,num);
    }
    }
}
int main()
{
    BST b;
    struct Node *root=NULL;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        root=b.insert(root,num);
    }
    cin>>val;
    b.Search(root,val);
    return 0;
}
