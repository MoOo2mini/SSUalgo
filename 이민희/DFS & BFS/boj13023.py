import sys

input = sys.stdin.readline

n, m = list(map(int, input().split(" ")))
adj_list = [[] for _ in range(n)]

for _ in range(m):
    row, col = list(map(int, input().split(" ")))
    adj_list[row].append(col)
    adj_list[col].append(row)

visited = [0] * n
maxValue = 0

def dfs(node, length):
    global maxValue
    maxValue = max(maxValue, length)
    if maxValue >= 5:
        print(1)
        sys.exit()
    visited[node] = 1
    for neighbor in adj_list[node]:
        if visited[neighbor] == 0:
            dfs(neighbor, length + 1)
    visited[node] = 0

for start in range(n):
    visited[start] = 1
    dfs(start, 1)
    visited[start] = 0

print(0)
