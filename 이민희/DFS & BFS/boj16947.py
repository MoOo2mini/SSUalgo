# DFS 문제, 사이클 구현
# visited 했던 곳으로 다시 돌아오면 사이클. 사이클 노드들은 저장해놓기.
# 1 - 2 - 5 - 1 이렇게 되면 사이클이다!

import sys
input = sys.stdin.readline

n = int(input())
arr = [[] for _ in range(n)]

for _ in range(n) :
    row, col = list(map(int, input().split()))
    row -= 1
    col -= 1
    if not row in arr[col] :
        arr[col].append(row)
    if not col in arr[row] :
        arr[row].append(col)

visited = [0] * n
ans = False

def dfs(idx) :
    global ans
    for i in range(len(arr[idx])) :
        if visited[arr[idx][i]] == 0 :
            visited[arr[idx][i]] = visited[idx] + 1
            dfs(i)
            visited[arr[idx][i]] = 0
        else :
            ans = True

for ____ in range(n) :
    visited[____] = 1
    dfs(____)
    if ans :
        print('cycle')
        exit()
    visited[____] = 0
