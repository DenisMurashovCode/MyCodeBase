
def matrix_chain_multiplication(dims):
    n = len(dims) - 1
    dp = [[float('inf')] * n for _ in range(n)]
    brackets = [[""] * n for _ in range(n)]
    matrices = [[None] * n for _ in range(n)] 
    for i in range(n):
        dp[i][i] = 0
        brackets[i][i] = "M" + str(i) 

    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1

            for k in range(i, j):
                cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]

                if cost < dp[i][j]:
                    dp[i][j] = cost
                    brackets[i][j] = "(" + brackets[i][k] + " × " + brackets[k + 1][j] + ")"
                    matrices[i][j] = brackets[i][j]  

    return dp[0][n - 1], matrices[0][n - 1]


dimensions = [10, 20, 5, 4, 30, 6]
min_operations, optimal_parentheses = matrix_chain_multiplication(dimensions)

print("Minimum number of operations:", min_operations)
print("Optimal parentheses:", optimal_parentheses)
