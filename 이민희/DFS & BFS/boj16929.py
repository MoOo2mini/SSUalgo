import sys
input = sys.stdin.readline

n, m = list(map(int, input().split()))
arr = []
for _ in range(n) :
    arr.append(list(input())[:m:])

# from collections import deque

visited = [[0] * m for _ in range(n)]

r = [-1, 1, 0, 0]
c = [0, 0, 1, -1]
answer = False

def dfs(row, col, cnt, start_row, start_col) :
    global answer
    if answer :
        return
    
    for i in range(4) :
        rr = row + r[i]
        cc = col + c[i]
        if 0 <= rr < n and 0 <= cc < m :
            if arr[rr][cc] == arr[row][col] :
                if rr == start_row and cc == start_col and cnt >= 4 :
                    answer = True
                    return
                elif visited[rr][cc] == 0 :
                    visited[row][col] = 1
                    dfs(rr, cc, cnt + 1, start_row, start_col)
                    visited[rr][cc] = 0

for i in range(n) :
    for j in range(m) :
        visited[i][j] = 1
        dfs(i, j, 1, i, j)
        if answer :
            print('Yes')
            exit()
if not answer :
    print('No')
