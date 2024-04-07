n, m = map(int, input().split())
origin_arr = []
virus_yx = []
for i in range(n) :
    tmp = list(map(int, input().split()))
    origin_arr.append(tmp)
    try :
        tmp.index(2)
        for j in range(n) :
            if (tmp[j] == 2) :
                virus_yx.append([i, j])
    except :
        pass

# M개의 바이러스 뽑기
Mlist = [0 for _ in range(len(virus_yx))]
visited = [0 for _ in range(len(virus_yx))]
Mlists = []
def select(Mlist, visited, idx, cnt) :
    if cnt == m :
        tmp = Mlist[:]
        Mlists.append(tmp)
        return

    for i in range(idx, len(Mlist)) :
        Mlist[i] = 1
        select(Mlist, visited, i + 1, cnt + 1)
        Mlist[i] = 0

select(Mlist, visited, 0, 0)

q = []
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

for i in range(n) :
    for j in range(n) :
        if (origin_arr[i][j] == 1) :
            origin_arr[i][j] = '-'
        elif (origin_arr[i][j] == 0) :
            origin_arr[i][j] = -1
minV = n ** 2 + 1

for getM in Mlists :
    arr = [origin_arr[_][:] for _ in range(n)]

    # 맵 만들기
    for idx in range(len(getM)) :
        y, x = virus_yx[idx]
        if (getM[idx] == 0) :
            arr[y][x] = '*'
        elif (getM[idx] == 1) :
            arr[y][x] = 0
            q.append([y, x])
    second = 0

    isVisited = [[-1 for _ in range(n)] for _ in range(n)]
    for virus in q:
        isVisited[virus[0]][virus[1]] = 0
    # 큐 돌리기
    while len(q) != 0 :
        y, x = q.pop(0)
        num = isVisited[y][x]

        for i in range(4) :
            yy = y + dy[i]
            xx = x + dx[i]

            if (0 <= yy < n and 0 <= xx < n) :
                if (arr[yy][xx] == -1) and isVisited[yy][xx] == -1 :
                    q.append([yy, xx])
                    isVisited[yy][xx] = num + 1
                    second = max(second, num + 1)
                elif (arr[yy][xx] == '*') and isVisited[yy][xx] == -1 :
                    q.append([yy, xx])
                    isVisited[yy][xx] = num + 1

    # 빈칸이 없는지 확인
    flag = True
    for i in range(n):
        for j in range(n):
            if (arr[i][j] == -1) and (isVisited[i][j] == -1):
                flag = False
    if flag :
        minV = min(minV, second)

if minV != (n ** 2 + 1) :
    print(minV)
else :
    print(-1)