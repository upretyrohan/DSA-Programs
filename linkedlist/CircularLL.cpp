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

Node *insertatBegin(Node *head, int data)
{
    // O(n)
    // Node *temp = new Node(data);
    // if (head == nullptr)
    // {
    //     temp->next = temp;
    // }
    // else
    // {
    //     Node *curr = head;

    //     while (curr->next != head)
    //     {
    //         curr = curr->next;
    //     }

    //     curr->next = temp;
    //     temp->next = head;
    // }

    // return temp;

    // O(1)

    Node *temp = new Node(data);
    if (head == nullptr)
    {
        temp->next = temp;
        return temp;
    }

    temp->next = head->next;
    head->next = temp;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;

    return head;
}

Node *insertatEnd(Node *head, int data)
{
    // O(1)
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        temp->next = temp;
        return temp;
    }


}

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
    printLL(insertatBegin(head, 5));
    printLL(insertatEnd(head,50));
    return 0;
}