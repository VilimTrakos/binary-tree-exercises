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



void Preorder(Btree<nodetype> &T){
	Stack<Btree<int>::node> S;
	Btree<int>::node n = T.Root();
	if (n != T.lambda){
		S.Push(n);
		while (!S.IsEmpty()){
			n = S.Top();
			S.Pop();
			std::cout << T.Label(n) << ", ";
			if (T.RightChild(n) != T.lambda)
				S.Push(T.RightChild(n));
			if (T.LeftChild(n) != T.lambda)
				S.Push(T.LeftChild(n));
		}
		std::cout << std::endl;
	}
	else
		std::cout << "Stablo je prazno" << std::endl;
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

	Preorder(T);
	return 0;
}
