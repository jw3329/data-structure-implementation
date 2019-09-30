#include "binary_search_tree.h"
#include <iostream>
#include "../queue/queue.h"
#include "../stack/stack.h"
using namespace std;

BinarySearchTree::BinarySearchTree() { root = nullptr; }

int max(int a, int b) { return a > b ? a : b; }

int heightHelper(TreeNode *subroot) {
    if (!subroot) return 0;
    return 1 + max(heightHelper(subroot->left), heightHelper(subroot->right));
}

int BinarySearchTree::height() { return heightHelper(root); }

TreeNode *BinarySearchTree::searchNode(int val) {
    if (!root) return nullptr;
    TreeNode *cur = root;
    while (cur) {
        if (cur->val == val) {
            return cur;
        } else if (cur->val > val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return nullptr;
}

void BinarySearchTree::insertNode(int val) {
    TreeNode *newNode = new TreeNode(val);
    if (!root) {
        root = newNode;
        return;
    }
    TreeNode *cur = root;
    while (cur) {
        if (cur->val == val) {
            delete newNode;
            return;
        } else if (cur->val > val) {
            if (cur->left)
                cur = cur->left;
            else {
                cur->left = newNode;
                return;
            }
        } else {
            if (cur->right)
                cur = cur->right;
            else {
                cur->right = newNode;
                return;
            }
        }
    }
}

TreeNode *getVeryLeft(TreeNode *subroot) {
    if (!subroot) return subroot;
    TreeNode *parent = nullptr;
    while (subroot->left) {
        parent = subroot;
        subroot = subroot->left;
    }
    if (parent) parent->left = nullptr;
    return subroot;
}

void deleteNodeHelper(TreeNode *&subroot, int val) {
    if (!subroot) return;
    if (subroot->val == val) {
        if (subroot->isLeaf())
            delete subroot;
        else if (subroot->hasChild()) {
            TreeNode *temp;
            if (subroot->left) {
                temp = subroot->left;
            } else {
                temp = subroot->right;
            }
            delete subroot;
            subroot = temp;
        } else {
            TreeNode *tempLeft = subroot->left;
            TreeNode *tempRight = subroot->right;
            TreeNode *leftLeaf = getVeryLeft(subroot->right);

            delete subroot;
            subroot = leftLeaf;
            subroot->left = tempLeft;
            subroot->right = tempRight;
        }
    } else {
        if (subroot->val > val) {
            deleteNodeHelper(subroot->left, val);
        } else {
            deleteNodeHelper(subroot->right, val);
        }
    }
}

void BinarySearchTree::deleteNode(int val) { deleteNodeHelper(root, val); }

void inOrderTraversalHelper(TreeNode *subroot) {
    if (!subroot) return;
    inOrderTraversalHelper(subroot->left);
    cout << " " << subroot->val << " ";
    inOrderTraversalHelper(subroot->right);
}

void BinarySearchTree::inOrderTraversal() {
    inOrderTraversalHelper(root);
    cout << endl;
}

void preOrderTraversalHelper(TreeNode *subroot) {
    if (!subroot) return;
    cout << " " << subroot->val << " ";
    preOrderTraversalHelper(subroot->left);
    preOrderTraversalHelper(subroot->right);
}

void BinarySearchTree::preOrderTraversal() {
    preOrderTraversalHelper(root);
    cout << endl;
}

void postOrderTraversalHelper(TreeNode *subroot) {
    if (!subroot) return;
    postOrderTraversalHelper(subroot->left);
    postOrderTraversalHelper(subroot->right);
    cout << " " << subroot->val << " ";
}

void BinarySearchTree::postOrderTraversal() {
    postOrderTraversalHelper(root);
    cout << endl;
}

void BinarySearchTree::levelOrderTraversal() {
    if (!root) return;
    Queue<TreeNode *> queue(10000);
    TreeNode *cur = root;
    queue.enqueue(cur);
    while (!queue.isEmpty()) {
        TreeNode *node = queue.dequeue();
        cout << node->val << " ";
        if (node->left) queue.enqueue(node->left);
        if (node->right) queue.enqueue(node->right);
    }
    cout << endl;
}

void deleteTreeNodes(TreeNode *subroot) {
    if (!subroot) return;
    deleteTreeNodes(subroot->left);
    deleteTreeNodes(subroot->right);
    delete subroot;
}

void BinarySearchTree::reversedOrderTraversal() {
    if (!root) return;
    Queue<TreeNode *> queue(10000);
    Stack<TreeNode *> stack(10000);
    TreeNode *cur = root;
    queue.enqueue(cur);
    while (!queue.isEmpty()) {
        TreeNode *node = queue.dequeue();
        stack.push(node);
        if (node->right) queue.enqueue(node->right);
        if (node->left) queue.enqueue(node->left);
    }
    while (!stack.isEmpty()) {
        cout << stack.pop()->val << " ";
    }
    cout << endl;
}

BinarySearchTree::~BinarySearchTree() { deleteTreeNodes(root); }