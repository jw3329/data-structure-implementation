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
                right, 1 +
                max(self.get_height(right.right), self.get_height(right.left)))
        self.set_height(
            root,
            1 + max(self.get_height(root.right), self.get_height(root.left)))

        return right

    def right_rotate(self, root):
        left = root.left
        if left:
            left_right = left.right if left else None
            left.right = root
            root.left = left_right

            self.set_height(
                left, 1 +
                max(self.get_height(left.left), self.get_height(left.right)))
        self.set_height(
            root,
            1 + max(self.get_height(root.right), self.get_height(root.left)))

        return left

    # def print(self):
    # def print_helper(root):
    #     if not root:
    #         return
    #     print_helper(root.left)
    #     print(f'{root.key}({root.count})', end=' ')
    #     print_helper(root.right)

    # print_helper(self.root)
    # def get_level_order_list():
    #     queue = [self.root]
    #     res = [self.root]
    #     while queue:
    #         curr = queue.pop(0)
    #         res.append(None if not curr else curr.key)
    #         if not curr:
    #             continue
    #         queue.append(curr.left)
    #         queue.append(curr.right)
    #     return res

    # def print_helper(level_list, spaces):

    # level_list = get_level_order_list()
    # print_helper(level_list,50)
    # # print root with first spaced 50

    # print_helper(root,50)

    def print(self):
        lines, _, _, _ = self._display_aux(self.root)
        for line in lines:
            print(line)

    def _display_aux(self, root):
        """Returns list of strings, width, height, and horizontal coordinate of the root."""
        # No child.
        if root.right is None and root.left is None:
            line = '%s(%s)' % (root.key, root.count)
            width = len(line)
            height = 1
            middle = width // 2
            return [line], width, height, middle

        # Only left child.
        if root.right is None:
            lines, n, p, x = self._display_aux(root.left)
            s = '%s' % root.key
            u = len(s)
            first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s
            second_line = x * ' ' + '/' + (n - x - 1 + u) * ' '
            shifted_lines = [line + u * ' ' for line in lines]
            return [first_line, second_line
                    ] + shifted_lines, n + u, p + 2, n + u // 2

        # Only right child.
        if root.left is None:
            lines, n, p, x = self._display_aux(root.right)
            s = '%s(%s)' % (root.key, root.count)
            u = len(s)
            first_line = s + x * '_' + (n - x) * ' '
            second_line = (u + x) * ' ' + '\\' + (n - x - 1) * ' '
            shifted_lines = [u * ' ' + line for line in lines]
            return [first_line, second_line
                    ] + shifted_lines, n + u, p + 2, u // 2

        # Two children.
        left, n, p, x = self._display_aux(root.left)
        right, m, q, y = self._display_aux(root.right)
        s = '%s(%s)' % (root.key, root.count)
        u = len(s)
        first_line = (x + 1) * ' ' + (n - x -
                                      1) * '_' + s + y * '_' + (m - y) * ' '
        second_line = x * ' ' + '/' + (n - x - 1 + u +
                                       y) * ' ' + '\\' + (m - y - 1) * ' '
        if p < q:
            left += [n * ' '] * (q - p)
        elif q < p:
            right += [m * ' '] * (p - q)
        zipped_lines = zip(left, right)
        lines = [first_line, second_line
                 ] + [a + u * ' ' + b for a, b in zipped_lines]
        return lines, n + m + u, max(p, q) + 2, n + u // 2

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

    def rebalance(self, root):
        self.set_height(
            root,
            1 + max(self.get_height(root.left), self.get_height(root.right)))

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

nums = [random.randint(0, 50) for _ in range(30)]

for num in nums:
    avl.insert(num)

# avl.print()

print(nums)

delete_list = random.sample(nums, len(nums) // 2)

print(delete_list)

print('before delete')
avl.print()

print('\nafter delete')
for num in delete_list:
    avl.delete(num)

avl.print()
print('')