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
int findheight(node* root)
{
    int leftheight,rightheight;
    if(root==NULL)
    {
        return -1;
    }
    leftheight=findheight(root->left);
    rightheight=findheight(root->right);
    return max(leftheight,rightheight)+1;

}
int main() {
	node* root = NULL;
     int n,number,a,height;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root=insertion(root,a);
    }
    height=findheight(root);
    cout<<height;
    return 0;
}

