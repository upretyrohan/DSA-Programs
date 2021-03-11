#include <stdio.h>

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int d)
    {
        data = d;
        prev = next =nullptr;
    }
};

void printDLL(Node* head)
{
    Node* curr = head;
    while(curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }

    printf("\n");
}

Node* insertatBegin(Node* head , int data)
{
    Node* temp = new Node(data);
    if (head == NULL)
        return temp;
    
    Node* curr = head;
    temp->next = curr;
    curr->prev = temp;

    return temp;
}

Node* insertatEnd(Node* head, int data)
{
    Node* temp = new Node(data);
    if (head == NULL)
        return temp;

    Node* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;

    return head;
}

int main()
{
    Node* head = insertatEnd(NULL, 10);
    head = insertatEnd(head, 20);
    head = insertatEnd(head, 30);
    head = insertatEnd(head, 40);
    printDLL(head);
}