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

// O(n) -Time
// O(H) - Space
void printinorder(Node* root)
{
    if (root != NULL)
    {
        printinorder(root->left);
        printf("%d ", root->key);
        printinorder(root->right);
    }
}

// O(n) -Time
// O(H) - Space
void printpreorder(Node* root)
{
    if (root != NULL)
    {
         printf("%d ", root->key);
         printpreorder(root->left);
         printpreorder(root->right);
    }
}

// O(n) -Time
// O(H) - Space
void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
// O(n) - Time
// Aux Space O(n) or Theta(W)
void printLevelOrderTraversal(Node* root)
{
    if (root == NULL) return;

   queue<Node*> q;
   q.push(root);
   while (q.empty() == false)
   {
        Node* curr = q.front();
        q.pop();
        printf("%d ", curr->key);
        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
   }
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    printinorder(root);
    printf("\n");
    printpreorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printLevelOrderTraversal(root);
    
}