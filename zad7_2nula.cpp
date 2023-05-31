#include"bin_pok.h"
#include"queue_pok.h"
#include"stog_pok.h"
#include<cmath>
//#include"bin_kur.h"
//#include"Bin_polje.h"
#include<iostream>
#include<stack>
using namespace std;


void printTree(Btree<char>::node node, int depth = 0) {
    if (node == NULL) return;

    printTree(node->right, depth + 1);

    for (int i = 0; i < depth; i++)
        cout << "  ";
    cout << node->label << endl;

    printTree(node->left, depth + 1);
}

int main() {
    Btree<char> tree('4');
    Btree<char>::node n = tree.Root();

    tree.CreateLeftChild(n, '7');  
    n = tree.LeftChild(n);
    tree.CreateLeftChild(n, '2');
    tree.CreateRightChild(n, '8');
    n = tree.LeftChild(n);
    tree.CreateRightChild(n, '3');
    n = tree.Parent(n);
    
    n = tree.RightChild(n);
    tree.CreateLeftChild(n, '1');

    n = tree.Root();
    
   	//cout<<"TU";
    tree.CreateRightChild(n, '6');
    n = tree.RightChild(n);
    tree.CreateLeftChild(n, '5');
    n = tree.LeftChild(n);
    tree.CreateLeftChild(n, '9');
    tree.CreateRightChild(n, '2');

    printTree(tree.Root());

    return 0;
}
