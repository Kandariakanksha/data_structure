#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *down;
};
void push (Node** head, int new_data)
{
    Node* new_node = new Node;
    new_node->right = NULL;
    new_node->data  = new_data;
    new_node->down = (*head);
    (*head)    = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->down;
    }
}

Node* merge( Node* a, Node* b )
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;
    Node* result;
    if (a->data < b->data)
    {
        result = a;
        result->down = merge( a->down, b );
    }
    else
    {
        result = b;
        result->down = merge( a, b->down );
    }

    return result;
}
Node* flatten (Node* root)
{
    if (root == NULL || root->right == NULL)
        return root;

    return merge( root, flatten(root->right) );
}

int main()
{
    Node* root = NULL;
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );
    root = flatten(root);
    printList(root);

    return 0;
}
