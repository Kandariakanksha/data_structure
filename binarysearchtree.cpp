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
bool Search(node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
void infix(node* root)
{
    if(root==NULL)
        return;
   infix(root->left);
   cout<<root->data;
   infix(root->right);
}
int main() {
	node* root = NULL;
     int n,number,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root=insertion(root,a);
    }
    cin>>number;
    if(Search(root,number)==true)
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl ;
        infix(root);
    return 0;
}
