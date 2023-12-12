class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x_root, y_root = self.find(x), self.find(y)
        if self.rank[x_root] < self.rank[y_root]:
            self.parent[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.parent[y_root] = x_root
        else:
            self.parent[y_root] = x_root
            self.rank[x_root] += 1


def kruskal(graph):
    edges = []
    for u in range(len(graph)):
        for v, weight in graph[u]:
            edges.append((weight, u, v))
    edges.sort()

    mst = []
    uf = UnionFind(len(graph))

    for weight, u, v in edges:
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            mst.append((u, v, weight))

    return mst


graph = [
[(1, 1), (2, 4), (3, 3)],
[(0, 1), (2, 2), (4, 4)],
[(0, 4), (1, 2), (3, 1), (4, 3)],
[(0, 3), (2, 1), (4, 1)],
[(1, 4), (2, 3), (3, 1)]
]

minimum_spanning_tree = kruskal(graph)
for u, v, weight in minimum_spanning_tree:
    print(f"Edge: ({u}, {v}), Weight: {weight}")
