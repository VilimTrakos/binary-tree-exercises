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

void Postorder(Btree<nodetype> &T){
	Btree<int>::node root = T.Root();
	Stack<Btree<int>::node> S;
	Btree<int>::node current = root;
	
	S.Push(T.Root());
	while (true){
		while (current != NULL){
			if (T.RightChild(current) != NULL){
				S.Push(T.RightChild(current));
			}
			S.Push(current);
			current = T.LeftChild(current);
		}
		
		current = S.Top();
		S.Pop();

		if (T.RightChild(current) != NULL && S.Top() == T.RightChild(current)){
			S.Pop();
			S.Push(current);
			current = T.RightChild(current);
		}
		else{
			std::cout << T.Label(current) << ", ";
			if (current == root)
				break;
			current = NULL;
		}

		if (S.IsEmpty())
			break;
	}
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

	Postorder(T);
	return 0;
}
