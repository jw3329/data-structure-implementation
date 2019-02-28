#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode {
   public:
    TreeNode();
    TreeNode(int val);
    TreeNode *left, *right;
    int val;
    bool isLeaf();
    bool hasChild();
    bool hasChildren();
};

#endif
