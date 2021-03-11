#include <stdio.h>

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *delHead(Node *head)
{
    return NULL;
}

Node *delAtPos(Node *head, int pos)
{
    return NULL;
}
void printLL(Node *head)
{
    if (head == nullptr)
        return;

    Node *curr = head;
    do
    {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    printLL(head);
    return 0;
}