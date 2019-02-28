#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "tree_node.h"

class BinarySearchTree {
   public:
    BinarySearchTree();
    int height();
    TreeNode *searchNode(int val);
    void insertNode(int val);
    void deleteNode(int val);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void levelOrderTraversal();
    void reversedOrderTraversal();
    ~BinarySearchTree();

   private:
    TreeNode *root;
};

#endif