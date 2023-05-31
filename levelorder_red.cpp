#include"bin_pok.h"
#include"queue_pok.h"
#include<cmath>
//#include"bin_kur.h"
//#include"Bin_polje.h"
#include<iostream>
#include<stack>

template <typename nodetype>
void Levelorder(Btree<nodetype> &tree){
	Queue<Btree<int>::node> Q;
	Q.Enqueue(tree.Root());
	do{
		Btree<int>::node n = Q.Front();
		Q.Dequeue();
		std::cout << tree.Label(n) << " ";
		if(tree.LeftChild(n) != tree.lambda)
			Q.Enqueue(tree.LeftChild(n));
		if(tree.RightChild(n) != tree.lambda)
			Q.Enqueue(tree.RightChild(n));
	} while (!Q.IsEmpty());
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

	Levelorder(T);
	return 0;
}
