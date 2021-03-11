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

Node *insertBegin(Node *head, int data)
{
    // O(1)
    if (head == NULL)
        return new Node(data);

    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

Node *insertEnd(Node* head, int data)
{
    // O(n)
    Node *temp = new Node(data);

    if (head == NULL)
        return temp;

    Node *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;

    return head;
}

Node* insertat(Node* head, int data, int pos)
{
    Node* temp = new Node(data);

    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    for (int i = 1; i <= pos -2 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL)
        return head;

    temp->next = curr->next;
    curr->next = temp;

    return head;

}


int main()
{
    Node* head = NULL;
    for (int i = 10; i <=50; i=i+10)
    {
        head = insertEnd(head, i);
    }
    head = insertBegin(head, 5);
    printList(head);

    printList(insertat(head,6,2));
    //  printList(insertat(head,2,16));
}
