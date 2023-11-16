class Heap:
    def __init__(self):
        self.size = 0
        self.heap = []

    def insert(self, val):
        # put into last element
        self.heap.append(val)
        # check with parent, swap until they are placed right
        curr = len(self.heap) - 1
        while curr > 0 and self.heap[curr] < self.heap[self.parent(curr)]:
            self.swap(curr, self.parent(curr))
            curr = self.parent(curr)

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return i * 2 + 1

    def right(self, i):
        return i * 2 + 2

    def pop(self):
        if not self.heap:
            raise Exception("no value")
        val = self.heap[0]
        # swap last with head
        # now decrement self.curr
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        curr = 0
        while curr < len(self.heap):
            # check if current is minimum
            left = self.left(curr)
            right = self.right(curr)
            if (left >= len(self.heap) or self.heap[curr] < self.heap[left]) and (
                right >= len(self.heap) or self.heap[curr] < self.heap[right]
            ):
                break
            # now we find smaller one
            smaller = left
            if smaller >= len(self.heap) or (
                right < len(self.heap) and self.heap[smaller] > self.heap[right]
            ):
                smaller = right
            # we found smaller
            # swap with smaller
            self.swap(curr, smaller)
            curr = smaller
        # now then from top to bottom, try to swap
        return val

    def is_empty(self):
        return not self.heap

    def min_heapify(self, i):
        if i >= len(self.heap):
            return
        # if parent is smaller, then stop
        left = self.left(i)
        right = self.right(i)
        if (left >= len(self.heap) or self.heap[i] < self.heap[left]) and (
            right >= len(self.heap) or self.heap[i] < self.heap[right]
        ):
            return
        # swapping smaller child, then we don't have to worry about if other is smaller, because it will be smaller always
        smaller = left
        if right < len(self.heap) and self.heap[right] < self.heap[smaller]:
            smaller = right
        self.swap(i, smaller)
        self.min_heapify(smaller)

    def heapify(self):
        # with current heap, make to heap structure

        def helper(index):
            if index >= len(self.heap):
                return
            left = self.left(index)
            right = self.right(index)
            # do all heapify for left and right
            helper(left)
            helper(right)
            # minimum to root
            smallest = index
            if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
                smallest = left
            if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
                smallest = right
            self.swap(index, smallest)
            self.min_heapify(smallest)

        helper(0)


if __name__ == "__main__":
    heap = Heap()
    heap.insert(9)
    heap.insert(8)
    heap.insert(5)
    heap.insert(6)
    heap.insert(7)
    heap.insert(4)
    heap.insert(3)
    heap.insert(1)
    heap.insert(2)

    while heap.heap:
        print(heap.pop())

    import random

    heap2 = Heap()
    heap2.heap = [random.randint(0, 1000000) for _ in range(1000000)]
    heap2.heapify()
    print(heap2.heap)
