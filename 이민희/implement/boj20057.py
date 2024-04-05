# 왼 아 오 위
dy = [0, 1, 0, -1]
dx = [-1, 0, 1, 0]
n = int(input())
arr = []
for _ in range(n) :
    tmp = list(map(int, input().split()))
    arr.append(tmp)

ci = n // 2
cj = n // 2

length = 1
cnt = 0
directionIdx = 0
currentLen = 0
gone = 0
hy = [[-2,-1,-1,-1, 0, 1, 1, 1, 2, 0],
    [ 0, 1, 0,-1, 2, 1, 0,-1, 0, 1],
    [ 2, 1, 1, 1, 0,-1,-1,-1,-2, 0],
    [ 0,-1, 0, 1,-2,-1, 0, 1, 0,-1]]
hx = [[ 0,-1, 0, 1,-2,-1, 0, 1, 0,-1],
    [-2,-1,-1,-1, 0, 1, 1, 1, 2, 0],
    [ 0, 1, 0,-1, 2, 1, 0,-1, 0, 1],
    [ 2, 1, 1, 1, 0,-1,-1,-1,-2, 0]]

value = [2, 10, 7, 1, 5, 10, 7, 1, 2]

while (ci, cj) != (0, 0) :
    ci = ci + dy[directionIdx]
    cj = cj + dx[directionIdx]
    currentLen += 1

    cValue = arr[ci][cj]
    # 흩날리기
    for i in range(9) :
        yy = ci + hy[directionIdx][i]
        xx = cj + hx[directionIdx][i]
        if (0 <= yy < n and 0 <= xx < n) :
            # 범위 내라면.. 날리기
            tmp = (cValue * value[i]) // 100
            arr[yy][xx] += tmp
            arr[ci][cj] -= tmp
        else :
            tmp = (cValue * value[i]) // 100
            gone += tmp
            arr[ci][cj] -= tmp
    yy = ci + hy[directionIdx][9]
    xx = cj + hx[directionIdx][9]
    if (0 <= yy < n and 0 <= xx < n):
        arr[yy][xx] += arr[ci][cj]
    else :
        gone += arr[ci][cj]
    arr[ci][cj] = 0
    # 위치 재설정
    if currentLen == length :
        directionIdx = (directionIdx + 1) % 4
        currentLen = 0
        if (cnt == 0) :
            cnt = 1
        elif (cnt == 1) :
            cnt = 0
            length += 1
print(gone)