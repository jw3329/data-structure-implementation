#include <ctime>
#include <iostream>
#include "binary_search_tree.h"
using namespace std;

int main() {
    BinarySearchTree *binarySearchTree = new BinarySearchTree();
    srand(time(nullptr));
    int count = 100;
    int firstNumber;
    cout << "Putting numbers : " << endl;
    for (int i = 0; i < count; i++) {
        int num = rand() % 5000;
        if (i == 0) firstNumber = num;
        cout << num << " ";
        binarySearchTree->insertNode(num);
    }
    cout << endl;
    cout << "Height of tree : " << endl;
    cout << binarySearchTree->height() << endl;
    cout << "Inorder Traversal : " << endl;
    binarySearchTree->inOrderTraversal();
    cout << "Removing node with value : " << firstNumber << endl;
    binarySearchTree->deleteNode(firstNumber);
    cout << "Inorder Traversal : " << endl;
    binarySearchTree->inOrderTraversal();
    cout << "Preorder Traversal : " << endl;
    binarySearchTree->preOrderTraversal();
    cout << "Postorder Traversal : " << endl;
    binarySearchTree->postOrderTraversal();
    cout << "Levelorder Traversal : " << endl;
    binarySearchTree->levelOrderTraversal();
    cout << "Reverseorder Traversal : " << endl;
    binarySearchTree->reversedOrderTraversal();
    delete binarySearchTree;
    return 0;
}