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
bool search_RecursiveSoln(Node* root , int x)
{
     if (root == NULL) return false;

     if (root->data == x) return true;
     if (x < root->data)
         return search_RecursiveSoln(root->left, x);
     else
         return search_RecursiveSoln(root->right, x);    
 }

// time complexity  - O(H+1) or O(H),  H- is height of binary search tree
// time complexity can be O(N), if tree is skewed(like a singly ll)
// Aux space - O(H), H function calls worst case
// Aux space iterative implmenetation - O(1)
bool search_IterativeSoln(Node* root , int x)
{
    // Iterative
    while (root != NULL)
    {
        if (root->data == x)
            return true;
        
        else if (x < root->data)
            root =root->left;
        
        else
            root=root->right;
    }

    return false;
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
    printf("Is present %d\n",search_RecursiveSoln(root, 16));
    printf("Is present %d\n",search_IterativeSoln(root, 1));
}