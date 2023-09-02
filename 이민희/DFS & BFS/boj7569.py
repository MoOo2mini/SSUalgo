import sys
input = sys.stdin.readline

n, m, h = list(map(int, input().split()))
arr = []

from collections import deque
dq = deque()

for _ in range(h) :
    tmp = []
    for __ in range(m) :
        tmp.append(list(map(int, input().split())))
        for i in range(len(tmp[-1])) :
            if tmp[-1][i] == 1 :
                dq.append([_, __, i])
    arr.append(tmp)

rl = [0, 0, 1, -1]
ud = [1, -1, 0, 0]

while dq :
    fir = dq.popleft()

    if fir[0] - 1 >= 0 : # up
        if arr[fir[0] - 1][fir[1]][fir[2]] == 0 :
            arr[fir[0] - 1][fir[1]][fir[2]] = arr[fir[0]][fir[1]][fir[2]] + 1
            dq.append([fir[0] - 1, fir[1], fir[2]])
    if fir[0] + 1 < h : # down
        if arr[fir[0] + 1][fir[1]][fir[2]] == 0 :
            arr[fir[0] + 1][fir[1]][fir[2]] = arr[fir[0]][fir[1]][fir[2]] + 1
            dq.append([fir[0] + 1, fir[1], fir[2]])
    
    for direction in range(4) :
        current_row = fir[1] + rl[direction]
        current_col = fir[2] + ud[direction]
        if 0 <= current_row < m and 0 <= current_col < n : 
            if arr[fir[0]][current_row][current_col] == 0 :
                arr[fir[0]][current_row][current_col] = arr[fir[0]][fir[1]][fir[2]] + 1
                dq.append([fir[0], current_row, current_col])
maxValue = -123

for height in arr :
    for row in height :
        if 0 in row :
            print(-1)
            exit()
        else :
            maxValue = max(max(row), maxValue)
print(maxValue - 1)