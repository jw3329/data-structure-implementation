import random


class TreeNode:

    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1
        self.count = 1


class AVLTree:

    def __init__(self):
        self.root = None

    def increment_count(self, root):
        root.count += 1

    def get_height(self, root):
        if not root:
            return 0
        return root.height

    def set_height(self, root, h):
        root.height = h

    def get_balance(self, root):
        return self.get_height(root.left) - self.get_height(root.right)

    def insert(self, key):

        def insert_helper(root, key):
            if not root:
                return TreeNode(key)
            if root.key == key:
                self.increment_count(root)
                return root
            if root.key < key:
                root.right = insert_helper(root.right, key)
            else:
                root.left = insert_helper(root.left, key)

            # self.set_height(
            #     root, 1 + max(self.get_height(root.left), self.get_height(root.right)))

            # balance = self.get_balance(root)

            # # if balance > 0 then it means that left height is longer than right by how long
            # # left right and left left
            # if balance > 1:
            #     if key > root.left.key:
            #         root.left = self.left_rotate(root.left)
            #     return self.right_rotate(root)

            # elif balance < -1:
            #     if key < root.right.key:
            #         root.right = self.right_rotate(root.right)
            #     return self.left_rotate(root)

            # return root
            return self.rebalance(root)
        self.root = insert_helper(self.root, key)

    def left_rotate(self, root):
        right = root.right
        if right:
            right_left = right.left
            right.left = root
            root.right = right_left

            self.set_height(
                right, 1 + max(self.get_height(right.right), self.get_height(right.left)))
        self.set_height(
            root, 1 + max(self.get_height(root.right), self.get_height(root.left)))

        return right

    def right_rotate(self, root):
        left = root.left
        if left:
            left_right = left.right if left else None
            left.right = root
            root.left = left_right

            self.set_height(
                left, 1 + max(self.get_height(left.left), self.get_height(left.right)))
        self.set_height(
            root, 1 + max(self.get_height(root.right), self.get_height(root.left)))

        return left

    def print(self):

        def print_helper(root):
            if not root:
                return
            print_helper(root.left)
            print(f'{root.key}({root.count})', end=' ')
            print_helper(root.right)

        print_helper(self.root)

    def delete(self, key):

        def delete_helper(root, key):
            if not root:
                return None
            if root.key < key:
                root.right = delete_helper(root.right, key)
            elif root.key > key:
                root.left = delete_helper(root.left, key)
            else:
                # decrease if count is more than 1
                if root.count > 1:
                    root.count -= 1
                    return root

                if not root.left:
                    return root.right
                elif not root.right:
                    return root.left
                else:
                    min_node = self.get_minimum_node(root.right)
                    root.key = min_node.key
                    root.count = min_node.count
                    # make min node count == 1 so that it can be deleted right away
                    min_node.count = 1
                    root.right = delete_helper(root.right, min_node.key)

            return self.rebalance(root)

        self.root = delete_helper(self.root, key)

    def rebalance(self,root):
        self.set_height(
            root, 1 + max(self.get_height(root.left), self.get_height(root.right)))

        balance = self.get_balance(root)

        # if balance > 0 then it means that left height is longer than right by how long
        # left right and left left
        if balance > 1:
            if self.get_balance(root.left) < 0:
                root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        elif balance < -1:
            if self.get_balance(root.right) > 0:
                root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    def get_minimum_node(self, root):
        if not root or not root.left:
            return root
        return self.get_minimum_node(root.left)


avl = AVLTree()

nums = [random.randint(0, 10) for _ in range(10)]

# nums = [9, 5, 10, 0, 6, 11, -1, 1, 2,1,1,1,1,1]

for num in nums:
    avl.insert(num)

# avl.print()

print(nums)

print(nums[:len(nums) // 2])

print('before delete')
avl.print()

print('\nafter delete')
for num in nums[:len(nums) // 2]:
    avl.delete(num)

avl.print()
