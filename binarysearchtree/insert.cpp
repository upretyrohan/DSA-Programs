#include <stdio.h>
#include <queue>
/*  10
    / \
   5  20
  /   / \ 
3    18 80
    /
    16
*/

struct Node
{
    int data;
    Node *left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void printBST(Node* root)
{
    // Level Order Traversal
    if (root == NULL) return;

    std::queue<Node*> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node* curr = q.front();
        q.pop();
        printf("%d ",curr->data);
        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
    }
}


// time complexity  - O(H+1) or O(H),  H- is height of binary search tree
// time complexity can be O(N), if tree is skewed(like a singly ll)
// Aux space - O(H), H function calls worst case
// Aux space iterative implmenetation - O(1)
Node* insert_RecursiveSoln(Node* root, int x)
{
    // Recursive solution
    if (root == NULL) return new Node(x);
 
    if (x == root->data)
        return root;

    if (x < root->data)
        root->left = insert_RecursiveSoln(root->left,x);

    if (x > root->data)
        root->right = insert_RecursiveSoln(root->right,x);
}

int main()
{
    Node* root  = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);
    root->right->left = new Node(16);
    printBST(root);
    printBST(insert_RecursiveSoln(root, 6));
}