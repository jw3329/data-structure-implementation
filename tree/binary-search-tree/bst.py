class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, val):
        def helper(root):
            if not root:
                return TreeNode(val)
            if val <= root.val:
                root.left = helper(root.left)
            else:
                root.right = helper(root.right)
            return root

        self.root = helper(self.root)

    def inorder(self):
        def helper(root):
            if not root:
                return
            helper(root.left)
            print(root.val)
            helper(root.right)

        helper(self.root)

    def level_order(self):
        queue = [self.root]
        while queue:
            curr = queue.pop(0)
            if not curr:
                continue
            print(curr.val)
            queue.append(curr.left)
            queue.append(curr.right)

    def find_left_most(self, root):
        while root.left:
            root = root.left
        return root

    def delete(self, val):
        # if duplicate exists, then remove left most value, istead of root
        def helper(root):
            if not root:
                return None, None
            if val > root.val:
                right_root, removed = helper(root.right)
                root.right = right_root
                return root, removed
            left_root, left_removed = helper(root.left)
            root.left = left_root
            # if nothing removed, then we check if root val is same, if root is same, then remove root, else, don't do anything
            if left_removed:
                return root, left_removed
            # nothing removed
            if val != root.val:
                return root, None
            # same case
            # check if root is leaf
            if not root.left and not root.right:
                return None, root
            # if one child
            if not root.left or not root.right:
                return root.left or root.right, root
            # if two nodes are there
            # with right node, left most node left will be left node
            left_most = self.find_left_most(root.right)
            left_most.left = root.left
            return root.right, root

        # return removed node
        root, _ = helper(self.root)
        self.root = root


if __name__ == "__main__":
    bst = BST()
    for i in range(50, -1, -1):
        bst.insert(i)
        bst.insert(i)
    print("inorder:")
    bst.inorder()
    print("level:")
    bst.level_order()
    for i in range(100):
        bst.delete(i)
        bst.delete(i)
    print("level:")
    bst.level_order()
