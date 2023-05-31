#include"bin_pok.h"
#include"queue_pok.h"
#include<cmath>
//#include"bin_kur.h"
//#include"Bin_polje.h"
#include<iostream>
#include<stack>
#include <cstdlib>

typedef int elementtypeh;
typedef Btree<elementtypeh> heap;

void InitH(heap &H){
	H = heap();
}

bool IsEmptyH(heap H){
	return H.IsEmpty();
}


void InsertH(heap &H, elementtypeh x){
	if(IsEmptyH(H))
		H.CreateRoot(x);
	else{
		heap::node n = H.Root();
		while(H.LeftChild(n) != NULL || H.RightChild(n) != NULL){
			if(H.LeftChild(n) != NULL)
				n = H.LeftChild(n);
			else
				n = H.RightChild(n);
		}
		if(H.LeftChild(n) == NULL)
			H.CreateLeftChild(n, x);
		else
			H.CreateRightChild(n, x);
	}
}

void DeleteRootH(heap &H){
	if(!IsEmptyH(H)){
		heap::node n = H.Root();
		if(H.LeftChild(n) == NULL && H.RightChild(n) == NULL){
			H.Delete(n);
		}
		else{
			heap::node p = n;
			while(H.LeftChild(p) != NULL || H.RightChild(p) != NULL){
				if(H.RightChild(p) != NULL)
					p = H.RightChild(p);
				else
					p = H.LeftChild(p);
			}
			H.ChangeLabel(n, H.Label(p));
			H.Delete(p);
		}
	}
	else
		std::cout << "Heap je prazan" << std::endl;
}

elementtypeh RootLabelH(heap &H){
	if(!IsEmptyH(H))
		return H.Label(H.Root());
	else{
		std::cout << "Heap je prazan" << std::endl;
		return 0;
	}
}

int main(){
	heap H;
	InitH(H);

	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		std::cout << "Unesite " << i + 1 << ". element: ";
		std::cin >> x;
		InsertH(H, x);
	}

	std::cout << "Sortirani elementi su: ";
	for(int i = 0; i < n; i++){
		std::cout << RootLabelH(H) << " ";
		DeleteRootH(H);
	}

	return 0;
}
