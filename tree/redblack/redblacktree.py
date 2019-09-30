class RedBlackTree:
    class TreeNode:
        def __init__(self, value, black=False):
            self.value = value
            self.black = black
            self.left = None
            self.right = None
            self.parent = None
            self.number = 1

        def flip_color(self):
            self.black = not self.black

        def to_black(self):
            self.black = True

        def to_red(self):
            self.black = False

        def is_leaf(self):
            return not self.left and not self.right

        def increment_number(self):
            self.number += 1

    def __init__(self):
        self.root = None

    def insert(self, value):
        self._insert_helper(self.TreeNode(value))

    def _insert_helper(self, node):
        if not self.root:
            node.to_black()
            self.root = node
            return
        if self.root is node:
            node.to_black()
            return

        curr = self.root
        while curr is self.root or not curr.is_leaf():
            if curr is node:
                break
            if curr.value == node.value:
                curr.increment_number()
                return
            if curr.value > node.value:
                if not curr.left:
                    curr.left = node
                    node.parent = curr
                curr = curr.left
            elif curr.value < node.value:
                if not curr.right:
                    curr.right = node
                    node.parent = curr
                curr = curr.right

        # inserted red node into tree, need to do operations
        parent = curr.parent
        grand_parent = parent.parent
        if not grand_parent: return
        uncle = grand_parent.right if grand_parent.left is parent else grand_parent.left

        if uncle and not uncle.black:
            parent.to_black()
            uncle.to_black()
            grand_parent.to_red()
            self._insert_helper(grand_parent)

        else:
            # left left case
            if grand_parent.left is parent and parent.left is curr:
                # right rotate grant_parent
                self.right_rotate(grant_parent)
            # left right case
            elif grand_parent.left is parent and parent.right is curr:
                # left rotate parent
                self.left_rotate(parent)
                # right rotate parent
                self.right_rotate(grand_parent)
            # right left case
            elif grant_parent.right is parent and parent.left is curr:
                # right rotate parent
                self.right_rotate(parent)
                # left rotate grand parent
                self.left_rotate(grand_parent)
            # right right case
            elif grand_parent.right is parent and parent.right is curr:
                self.left_rotate(grand_parent)
            self.grand_parent.black, self.parent.black = self.parent.black, self.grand_parent.black

    def right_rotate(self, node):
        node_left = node.left
        node_left_right = node_left.right
        node_left.right = node
        node.left = node_left_right
        if node.parent.left is node:
            node.parent.left = node_left
        else:
            node.parent.right = node_left
        node_left.parent = node.parent
        node.parent = node_left
        node_left_right.parent = node

    def left_rotate(self, node):
        node_right = node.right
        node_right_left = node_right.left
        node_right.left = node
        node.right = node_right_left
        # node.parent = node_right
        # if curr node is parent's node left
        if node.parent.left is node:
            node.parent.left = node_right
        else:
            node.parent.right = node_right
        node_right.parent = node.parent
        node.parent = node_right
        node_right_left.parent = node

    def print(self):
        def print_helper(root):
            if not root: return
            print_helper(root.left)
            print(root.value, end=' ')
            print_helper(root.right)

        print_helper(self.root)


rbtree = RedBlackTree()

import random

for i in range(100):
    rbtree.insert(random.randint(0, 100))

rbtree.print()