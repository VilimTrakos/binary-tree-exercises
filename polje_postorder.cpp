//#include"bin_pok.h"
#include"queue_pok.h"
#include"stog_pok.h"
#include<cmath>
//#include"bin_kur.h"
#include"Bin_polje.h"
#include<iostream>
#include<stack>
using namespace std;


void PostOrder(Btree<int>::node n, Btree<int> &B){
	if (n != B.lambda){
		PostOrder(B.LeftChild(n), B);
		PostOrder(B.RightChild(n), B);
		cout << B.Label(n) << ", ";
	}
	else
		return;
}

int main(void){
	Btree<int> B(4);
	B.CreateLeftChild(1, 7);
	B.CreateRightChild(1, 6);
	B.CreateLeftChild(2, 2);
	B.CreateRightChild(2, 8);
	B.CreateLeftChild(3,5);
	B.CreateRightChild(4, 3);
	B.CreateLeftChild(5, 1);
	B.CreateLeftChild(6, 9);
	B.CreateRightChild(6, 2);
	
	PostOrder(B.Root(), B);
	cout << endl;
}
