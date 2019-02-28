#include "tree_node.h"

TreeNode::TreeNode() {
    left = right = nullptr;
    val = 0;
}

TreeNode::TreeNode(int val) {
    left = right = nullptr;
    this->val = val;
}

bool TreeNode::isLeaf() { return !left && !right; }

bool TreeNode::hasChild() { return !(left && right) && (left || right); }

bool TreeNode::hasChildren() { return left && right; }