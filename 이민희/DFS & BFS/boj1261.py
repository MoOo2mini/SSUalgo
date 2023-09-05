import sys
from collections import deque

input = sys.stdin.readline
dq = deque()
dq.append([0, 0])

r = [-1, 1, 0, 0]
c = [0, 0, -1, 1]

col, row = list(map(int, input().split()))
arr = []
for _ in range(row) :
    arr.append(list(input())[:col:])

visited = [[-1] * col for _ in range(row)]
visited[0][0] = 0

while dq :
    cr, cc = dq.popleft()
    if cr == row - 1 and cc == col - 1 :
        print(visited[row - 1][col - 1])
    else :
        for i in range(4) :
            nr = cr + r[i]
            nc = cc + c[i]
            if 0 <= nr < row and 0 <= nc < col :
                if visited[nr][nc] == -1 :
                    if arr[nr][nc] == '1' :
                        visited[nr][nc] = visited[cr][cc] + 1
                        dq.append([nr, nc])
                    else :
                        visited[nr][nc] = visited[cr][cc]
                        dq.appendleft([nr, nc])