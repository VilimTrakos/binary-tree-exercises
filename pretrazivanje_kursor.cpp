//#include"bin_pok.h"
#include"queue_pok.h"
#include"stog_pok.h"
#include<cmath>
//#include"bin_kur.h"
#include"Bin_polje.h"
#include<iostream>
#include<stack>
using namespace std;


#include <iostream>

using namespace std;

struct node 
{
	int data;
	node *left;
	node *right;
	node *parent;
	bool flag;
};

//function for create new node
node* newNode(int data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	new_node->flag = true;
	return new_node;
}

//function for insert a node
void insert(node* &root, int data)
{
	if (root == NULL)
	{
		root = newNode(data);
		return;
	}

	node* temp = newNode(data);
	node* curr = root;
	node* parent = NULL;

	while (curr != NULL)
	{
		parent = curr;
		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	if (data < parent->data)
		parent->left = temp;
	else
		parent->right = temp;

	temp->parent = parent;
}

//function for init binary search tree
void InitBST(node* &root, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		insert(root, arr[i]);
}

//function for check if the binary search tree is empty
bool IsEmptyBST(node* root)
{
	if (root == NULL)
		return true;
	else
		return false;
}

//function for check if a node is present in binary search tree
bool IsNodeBST(node* root, int data)
{
	node* curr = root;
	while (curr != NULL)
	{
		if (data == curr->data)
			return true;
		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return false;
}

//function for delete a node in binary search tree
void DeleteBST(node* &root, int data)
{
	if (root == NULL)
		return;

	node* curr = root;

	while (curr != NULL && curr->data != data)
	{
		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	if (curr == NULL)
		return;

	if (curr->left == NULL && curr->right == NULL)
	{
		if (curr == root)
			root = NULL;
		else
		{
			if (curr->parent->left == curr)
				curr->parent->left = NULL;
			else
				curr->parent->right = NULL;
		}
		delete curr;
		return;
	}

	if (curr->left != NULL && curr->right == NULL)
	{
		if (curr == root)
			root = curr->left;
		else
		{
			if (curr->parent->left == curr)
				curr->parent->left = curr->left;
			else
				curr->parent->right = curr->left;
		}
		delete curr;
		return;
	}

	if (curr->left == NULL && curr->right != NULL)
	{
		if (curr == root)
			root = curr->right;
		else
		{
			if (curr->parent->left == curr)
				curr->parent->left = curr->right;
			else
				curr->parent->right = curr->right;
		}
		delete curr;
		return;
	}

	if (curr->left != NULL && curr->right != NULL)
	{
		node* temp = root;
		while (temp->left != NULL)
			temp = temp->left;

		int val = temp->data;
		DeleteBST(root, temp->data);
		curr->data = val;
	}
}

//function for dispose binary search tree
void DisposeBST(node* &root)
{
	if (root == NULL)
		return;
	DisposeBST(root->left);
	DisposeBST(root->right);
	delete root;
	root = NULL;
}

//function for print the binary search tree
void printBST(node* root)
{
	if (root != NULL)
	{
		printBST(root->left);
		cout << root->data << " ";
		printBST(root->right);
	}
}

// Main function
int main()
{
	int arr[] = { 4, 7, 2, 3, 8, 1, 6, 5, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	node* root = NULL;

	InitBST(root, arr, n);

	cout << "Binary Search Tree : ";
	printBST(root);
	cout << endl;

	cout << "Is Empty Binary Search Tree : " << IsEmptyBST(root) << endl;

	cout << "Is Node present in Binary Search Tree : " << IsNodeBST(root, 6) << endl;

	cout << "Delete node 6 in Binary Search Tree : ";
	DeleteBST(root, 6);
	printBST(root);
	cout << endl;

	DisposeBST(root);
	cout << "Binary Search Tree After Dispose : ";
	printBST(root);
	cout << endl;

	return 0;
}
