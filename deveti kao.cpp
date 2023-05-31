#include"bin_pok.h"
#include"queue_pok.h"
#include"stog_pok.h"
#include<cmath>
//#include"bin_kur.h"
//#include"Bin_polje.h"
#include<iostream>
#include<stack>
#include<iomanip>
using namespace std;

int main(){
	
	//creating binary tree
	Btree<char> tree('4');
	Btree<char>::node root = tree.Root();
	tree.CreateLeftChild(root, '7');
	tree.CreateRightChild(root, '6');
	Btree<char>::node leftChild = tree.LeftChild(root);
	Btree<char>::node rightChild = tree.RightChild(root);
	tree.CreateLeftChild(leftChild, '2');
	tree.CreateRightChild(leftChild, '8');
	tree.CreateLeftChild(rightChild, '5');
	tree.CreateLeftChild(leftChild->left, '3');
	tree.CreateLeftChild(rightChild->left, '1');
	tree.CreateRightChild(rightChild->left, '9');
	tree.CreateRightChild(rightChild->left, '2');

	//Printing labels of binary tree
	std::cout << "root: \t\t" << tree.Label(root) << std::endl;
	std::cout << "lvl1: \t" << tree.Label(leftChild) << "\t\t" << tree.Label(rightChild) << std::endl;
	std::cout << "lvl2: \t" << tree.Label(leftChild->left) << "\t" << tree.Label(leftChild->right) << "\t" << tree.Label(rightChild->left) << std::endl;
	std::cout << "lvl3: \t" << tree.Label(leftChild->left->left) << "\t" << tree.Label(rightChild->left->left) << "\t\t" << tree.Label(rightChild->left->right) << "\t" << tree.Label(rightChild->left->right) << std::endl;

	return 0;
}
