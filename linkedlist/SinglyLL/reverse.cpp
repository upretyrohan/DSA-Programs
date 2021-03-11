#include <stdio.h>

struct Node
{
    int data;
    Node *next;

    Node(int key)
    {
        data = key;
        next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }

    printf("\n");
}

// Time Complexity - O(n)
// Auxillary Space - O(1) 
Node* reverseLL(Node* head)
{
    if (head == NULL) return NULL;

    Node* prev = NULL;
    Node * curr = head;
    while (curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr  = temp;
    }

    return prev;
}
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printList(reverseLL(head));
}