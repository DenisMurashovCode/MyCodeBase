import itertools


def tsp_brute_force(C):
    n = len(C)
    best_path = None
    best_cost = float('inf')

    for perm in itertools.permutations(range(1, n)):
        path = [0] + list(perm) + [0]
        cost = 0
        for i in range(n):
            cost += C[path[i]][path[i+1]]
        if cost < best_cost:
            best_cost = cost
            best_path = path

    return best_path, best_cost



def tsp_branch_and_bound(C):
    n = len(C)
    best_path = None
    best_cost = float('inf')
    visited = [False] * n
    
    def dfs(path, cost, level):
        nonlocal best_path, best_cost
        if level == n:
            cost += C[path[-1]][path[0]]
            if cost < best_cost:
                best_cost = cost
                best_path = path[:]
        else:
            for i in range(n):
                if not visited[i]:
                    visited[i] = True
                    path.append(i)
                    if cost + C[path[-2]][i] < best_cost:
                        dfs(path, cost + C[path[-2]][i], level + 1)
                    path.pop()
                    visited[i] = False
    
    dfs([0], 0, 1)
    best_path.append(0)
    
    return best_path, best_cost



C = [
    [float('inf'), 13, 7, 5, 2, 9],
    [8, float('inf'), 4, 7, 5, float('inf')],
    [8, 4, float('inf'), 3, 6, 2],
    [5, 8, 1, float('inf'), 0, 1],
    [float('inf'), 6, 1, 4, float('inf'), 9],
    [10, 0, 8, 3, 7, float('inf')]
]


path1, cost1 = tsp_brute_force(C)
path2, cost2 = tsp_branch_and_bound(C)

print("Optimal path1:", path1)
print("Optimal cost1:", cost1)
print("------------------------------------")
print("Optimal path2:", path2)
print("Optimal cost2:", cost2)
