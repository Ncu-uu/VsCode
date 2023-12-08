def wallshall(n, m, relations):
    # 初始化胜负关系矩阵
    matrix = [[0] * n for _ in range(n)]
    for a, b in relations:
        matrix[a-1][b-1] = 1

    # 使用Floyd-Warshall算法更新胜负关系矩阵
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if matrix[i][k] and matrix[k][j]:
                    matrix[i][j] = 1

    # 统计能确定最终排名的牛的数量
    count = 0
    for i in range(n):
        if sum(matrix[i]) + sum(row[i] for row in matrix) == n - 1:
            count += 1

    return count

n, m = map(int, input().split())
relations = [list(map(int, input().split())) for _ in range(m)]
result = wallshall(n, m, relations)
print(result)
