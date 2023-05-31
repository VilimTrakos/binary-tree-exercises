#include"bin_pok.h"
#include"queue_pok.h"
#include"stog_pok.h"
#include<cmath>
//#include"bin_kur.h"
//#include"Bin_polje.h"
#include<iostream>
#include<stack>
using namespace std;

using namespace std;


void printTree(Btree<int>::node, int level);

int main(){
    Btree<int> bt(4);
    bt.CreateLeftChild(bt.Root(), 7);
    bt.CreateRightChild(bt.Root(), 6);
    bt.CreateLeftChild(bt.LeftChild(bt.Root()), 2);
    bt.CreateRightChild(bt.LeftChild(bt.Root()), 8);
    bt.CreateLeftChild(bt.RightChild(bt.Root()), 5);
    bt.CreateLeftChild(bt.LeftChild(bt.RightChild(bt.Root())), 9);
    bt.CreateRightChild(bt.LeftChild(bt.RightChild(bt.Root())), 2);
    bt.CreateLeftChild(bt.LeftChild(bt.LeftChild(bt.Root())), 3);
    bt.CreateRightChild(bt.LeftChild(bt.LeftChild(bt.Root())), 1);

    printTree(bt.Root(), 0);

    return 0;
}

void printTree(Btree<int>::node node, int level){
    if(node != NULL){
        printTree(node->right, level + 1);
        for(int i = 0; i < level; i++)
            cout << "\t";
        cout << node->label << endl;
        printTree(node->left, level + 1);
    }
}
