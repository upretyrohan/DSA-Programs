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

Node* insertatBegin(Node *head, int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        head->next = head;
        return head;
    }

    Node* curr = head;
    Node* temp = new Node(data);
    int tempdata = curr->data;
    curr->data = temp->data;
    temp->next = curr;
    temp->data = tempdata;
}

int main()
{
    Node * head = nullptr;
    head = insertatBegin(head, 10);
    head = insertatBegin(head, 20);
    head = insertatBegin(head, 30);
    head = insertatBegin(head, 40);
}