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

//Auxillay space O(H+1) H->Height - h+1 recursive call
// Time complexity- Constant work at evry node and if n nodes then 0(1)*n = O(n)
int heightOfBT(Node* root)
{
    if (root == NULL)
        return 0;

    return max(heightOfBT(root->left), heightOfBT(root->right)) +1;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    printf("Height of binary tree %d",heightOfBT(root));

}