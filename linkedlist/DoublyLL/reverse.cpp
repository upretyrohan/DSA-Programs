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


// O(N)
// O(1)
Node* reverseDL(Node* head)
{
    if (head == NULL) return nullptr;

    if (head->next == NULL) return head;

    Node* curr = head; Node* prev = NULL;
    while (curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }

    return prev->prev;
}

int main()
{
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printDLL(reverseDL(head));
}