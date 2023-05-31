#include<iostream>
#include<stack>
using namespace std;
 
// A binary tree node
struct Node
{
    int data;
    struct Node* left, *right;
};
 
// A utility function to create a new Binary Tree node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// An iterative process to print preorder traversal of Binary tree
void inOrder(struct Node *root)
{
    // Base Case
    if (root == NULL) return;
 
    // Create an empty stack and push root to it
    struct Node *node = root;
    stack<Node *> s;
 
    // Current node is root
    while (true)
    {
        /* Reach the left most Node of the current Node */
        if (node !=  NULL)
        {
            /* place pointer to a tree node on the stack before traversing
              the node's left subtree */
            s.push(node);
            node = node->left;
        }
 
        /* BackTrack from the empty subtree and visit the Node
           at the top of the stack; however, if the stack is empty,
           you are done */
        else
        {
            if (s.empty())
                return;
 
            /* Pop the top item from stack and print it */
            node = s.top();
            s.pop();
            cout << node->data << " ";
 
            /* We have visited the node and its left subtree.
              Now, it's right subtree's turn */
            node = node->right;
        }
   }
}
 
/* Driver program to test above functions*/
int main()
{
 
    /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 
  inOrder(root);
 
  getchar();
  return 0;
}
