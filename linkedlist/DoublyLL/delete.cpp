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

Node* delHead(Node* head)
{
    if (head == NULL) return NULL;

    Node * curr = head->next;
    delete head;
    curr->prev = NULL;
    return curr;
}

Node* delTail(Node* head)
{
    if (head == NULL) return NULL;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->prev->next = NULL;
    delete curr;
    return head;
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
    printDLL(head);
    //printDLL(delHead(head));
    printDLL(delTail(head));
}