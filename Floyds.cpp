#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

int detectloop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
           cout<<"loop found";
           return 1;
        }
    }
    return 0;
}
int main()
{
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;
    detectloop(head);

    return 0;
}
