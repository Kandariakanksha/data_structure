#include<iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

node* getnewnode(int data) {
	node* newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

node* insertion(node* root,int data) {
	if(root == NULL) {
		root = getnewnode(data);
	}
	else if(data <= root->data) {
		root->left = insertion(root->left,data);
	}
	else {
		root->right = insertion(root->right,data);
	}
	return root;
}
int findmin(node* root)
{
    if(root==NULL)
    {
        cout<<"wrong";
        return -1;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
int findmax(node* root)
{
    if(root==NULL)
    {
        cout<<"wrong";
        return -1;
    }
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
int main() {
	node* root = NULL;
     int n,number,a,minimum,maximum;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root=insertion(root,a);
    }
    minimum=findmin(root);
    cout<<minimum<<endl;
    maximum=findmax(root);
    cout<<maximum<<endl;
    return 0;
}
