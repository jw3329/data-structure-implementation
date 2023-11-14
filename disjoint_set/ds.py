class DisjointSet:
    def __init__(self):
        self.parent = dict()

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        # make parent of b to a
        self.parent[b] = a

    def find(self, a):
        if a not in self.parent:
            self.parent[a] = a
        if a == self.parent[a]:
            return a
        found = self.find(self.parent[a])
        self.parent[a] = found
        return found


if __name__ == "__main__":
    ds = DisjointSet()

    ds.union("a", "b")
    ds.union("b", "c")
    ds.union("c", "d")
    ds.union("e", "f")

    print(ds.find("a"))
    print(ds.find("b"))
    print(ds.find("c"))
    print(ds.find("e"))
    print(ds.find("f"))
