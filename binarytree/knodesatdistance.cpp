
#include <stdio.h>
#include <algorithm> 
#include <queue>
using namespace std;
struct  Node
{
    int key;
    Node* left;
    Node* right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// O(n)
// O(H)
void printKNodesAtADistance(Node* root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
        printf("%d",root->key);

    printKNodesAtADistance(root->left, k-1);
    printKNodesAtADistance(root->right, k-1);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);   
}