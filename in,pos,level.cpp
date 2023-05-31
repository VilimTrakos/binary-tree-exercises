/*Please make me c++ program for preorder, inorder,levelorder,postorder traversal  of binary tree, recursions CANT be used
given tree is:
        4
      /   \
7         6
/ \      / \
2 8    5
\ /     / \
3 1   9   2
*/
// C++ Program for Preorder, Inorder, Levelorder, Postorder Traversal of Binary Tree
#include <iostream> 
#include<stack>
#include<queue>
using namespace std; 

// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new Binary Tree node 
struct Node* newNode(int item) 
{ 
	struct Node* temp = new struct Node; 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Preorder traversal of a binary tree 
void preOrder(struct Node* root) 
{ 
	if (root == NULL) 
		return; 

	cout<< root->data<<" "; 
	preOrder(root->left); 
	preOrder(root->right); 
} 

// Inorder traversal of a binary tree 
void inOrder(struct Node* root) 
{ 
	if (root == NULL) 
		return; 

	inOrder(root->left); 
	cout<< root->data<<" "; 
	inOrder(root->right); 
} 

// Levelorder traversal of a binary tree 
void levelOrder(struct Node* root) 
{ 
	if (root == NULL) 
		return; 

	// Create an empty queue for level order tarversal 
	queue<Node *> q; 

	// Enqueue Root and initialize height 
	q.push(root); 

	while (q.empty() == false) 
	{ 
		// Print front of queue and remove it from queue 
		Node *node = q.front(); 
		cout << node->data << " "; 
		q.pop(); 

		/* Enqueue left child */
		if (node->left != NULL) 
			q.push(node->left); 

		/*Enqueue right child */
		if (node->right != NULL) 
			q.push(node->right); 
	} 
} 

// Postorder traversal of a binary tree 
void postOrder(struct Node* root) 
{ 
	if (root == NULL) 
		return; 

	postOrder(root->left); 
	postOrder(root->right); 
	cout<< root->data<<" "; 
} 

// Driver program to test above functions 
int main() 
{ 
	struct Node *root = newNode(4); 
	root->left = newNode(7); 
	root->right = newNode(6); 
	root->left->left = newNode(2); 
	root->left->right = newNode(8); 
	root->left->left->right = newNode(3); 
	root->left->right->left = newNode(1); 
	root->right->left = newNode(5); 
	root->right->right = newNode(9); 
	root->right->right->right = newNode(2); 

	cout << "Preorder traversal of binary tree is \n"; 
	preOrder(root); 

	cout << "\nInorder traversal of binary tree is \n"; 
	inOrder(root); 

	cout << "\nLevelorder traversal of binary tree is \n"; 
	levelOrder(root); 

	cout << "\nPostorder traversal of binary tree is \n"; 
	postOrder(root); 

	return 0; 
}
