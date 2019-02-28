#include <ctime>
#include <iostream>
#include "binary_tree.h"
using namespace std;

int main() {
    BinaryTree *binaryTree = new BinaryTree();
    srand(time(nullptr));
    int count = 100;
    int firstNumber;
    cout << "Putting numbers : " << endl;
    for (int i = 0; i < count; i++) {
        int num = rand() % 5000;
        if (i == 0) firstNumber = num;
        cout << num << " ";
        binaryTree->insertNode(num);
    }
    cout << endl;
    cout << "Height of tree : " << endl;
    cout << binaryTree->height() << endl;
    cout << "Inorder Traversal : " << endl;
    binaryTree->inOrderTraversal();
    cout << "Removing node with value : " << firstNumber << endl;
    binaryTree->deleteNode(firstNumber);
    cout << "Inorder Traversal : " << endl;
    binaryTree->inOrderTraversal();
    cout << "Preorder Traversal : " << endl;
    binaryTree->preOrderTraversal();
    cout << "Postorder Traversal : " << endl;
    binaryTree->postOrderTraversal();
    cout << "Levelorder Traversal : " << endl;
    binaryTree->levelOrderTraversal();
    cout << "Reverseorder Traversal : " << endl;
    binaryTree->reversedOrderTraversal();
    delete binaryTree;
    return 0;
}