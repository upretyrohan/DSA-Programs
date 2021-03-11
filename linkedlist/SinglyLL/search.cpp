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

int searchLL(Node* head,int data)
{
    int pos = 1;

    Node* curr = head;

    while (curr != NULL)
    {
        if (curr->data == data)
        {
            return pos;
        }
        else{
            pos++;
            curr = curr->next;
        }
       
    }
    return -1 ;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int pos = searchLL(head, 40);
    printf("%d ", pos);
    int pos1 = searchLL(head, 50);
    printf("%d ", pos1);
}