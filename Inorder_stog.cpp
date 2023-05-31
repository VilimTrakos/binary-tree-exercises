#include"bin_pok.h"
#include"queue_pok.h"
#include"stog_pok.h"
#include<cmath>
//#include"bin_kur.h"
//#include"Bin_polje.h"
#include<iostream>
#include<stack>
using namespace std;

template <typename nodetype>

void Inorder(Btree<nodetype> T){
	Stack<Btree<int>::node> S;
	Btree<int>::node root = T.Root();
	Btree<int>::node current = root;

	while (1){
		if (current != T.lambda){
			S.Push(current);
			current = T.LeftChild(current);
		}
		else{
			if (!S.IsEmpty()){
				current = S.Top();
				std::cout << T.Label(current) << " ";
				S.Pop();
				current = T.RightChild(current);
			}
			else
				break;
		}
	}
	std::cout << std::endl;
}

int main(){
	Btree<int> T(4);
	Btree<int>::node root = T.Root();
	T.CreateLeftChild(root, 7);
	T.CreateRightChild(root, 6);
	Btree<int>::node leftchild = T.LeftChild(root);
	T.CreateLeftChild(leftchild, 2);
	T.CreateRightChild(leftchild, 8);
	Btree<int>::node leftgrandchild = T.LeftChild(leftchild);
	T.CreateRightChild(leftgrandchild, 3);
	Btree<int>::node rightgrandchild = T.RightChild(leftchild);
	T.CreateLeftChild(rightgrandchild, 1);
	Btree<int>::node rightchild = T.RightChild(root);
	T.CreateLeftChild(rightchild, 5);
	Btree<int>::node rightgrandgrandchild = T.LeftChild(rightchild);
	T.CreateLeftChild(rightgrandgrandchild, 9);
	T.CreateRightChild(rightgrandgrandchild, 2);

	Inorder(T);
	return 0;
}
