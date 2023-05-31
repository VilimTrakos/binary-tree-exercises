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


bool symmetrical(Btree<char>::node n1, Btree<char>::node n2) {
    if (n1 == NULL && n2 == NULL) return true;
    if (n1 == NULL || n2 == NULL) return false;
    if (n1->label != n2->label) return false;
    return symmetrical(n1->left, n2->right) && symmetrical(n1->right, n2->left);
}

int main() {
    int N;
    cin >> N;
    Btree<char> tree;
    if (N > 0) {
        char l;
        cin >> l;
        tree.CreateRoot(l);
        Btree<char>::node root = tree.Root();
        for (int i = 1; i < N; i++) {
            char l;
            cin >> l;
            if (i % 2 == 1) {
                tree.CreateLeftChild(root, l);
            }
            else {
                tree.CreateRightChild(root, l);
            }
        }
    }
    cout << ((symmetrical(tree.Root(), tree.Root())) ? "TRUE" : "FALSE") << endl;
    return 0;
}
