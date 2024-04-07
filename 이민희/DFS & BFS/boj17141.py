n, m = map(int, input().split())

origin_arr = []
viruses = []
for i in range(n) :
    tmp = list(map(int, input().split()))
    origin_arr.append(tmp)
    try :
        tmp.index(2)
        for j in range(n) :
            if (tmp[j] == 2) :
                viruses.append([i, j])
    except :
        pass

virusList = []
Mlist = [0 for _ in range(len(viruses))]
def selectM(Mlist, idx, cnt) :
    if cnt == m :
        tmp = Mlist[:]
        virusList.append(tmp)
        return

    for i in range(idx, len(viruses)) :
        Mlist[i] = 1
        selectM(Mlist, i + 1, cnt + 1)
        Mlist[i] = 0

selectM(Mlist, 0, 0)
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
second = n ** 2 + 1
for isVirus in virusList :
    arr = [origin_arr[x][:] for x in range(n)]

    visited = [[-1 for _ in range(n)] for _ in range(n)]
    q = []
    for i in range(len(isVirus)) :
        if (isVirus[i] == 1) :
            visited[viruses[i][0]][viruses[i][1]] = 0
            q.append(viruses[i])
        else :
            arr[viruses[i][0]][viruses[i][1]] = 0

    cnt = 0
    while len(q) != 0 :
        y, x = q.pop(0)
        currentSecond = visited[y][x]
        for i in range(4) :
            yy = dy[i] + y
            xx = dx[i] + x

            if (0 <= yy < n and 0 <= xx < n) :
                if (arr[yy][xx] != 1 and visited[yy][xx] == -1) :
                    visited[yy][xx] = currentSecond + 1
                    q.append([yy, xx])
                    cnt = max(currentSecond + 1, cnt)
    # 모든 칸을 다 퍼뜨렸는지 확인
    isDone = True

    for i in range(n) :
        for j in range(n) :
            if (arr[i][j] == 0 and visited[i][j] == -1) :
                isDone = False
    if isDone :
        second = min(second, cnt)
if (second == n**2 + 1) :
    print(-1)
else :
    print(second)

# 5 1
# 2 1 1 1 1
# 1 2 0 1 1
# 1 1 1 1 1
# 1 1 1 1 1
# 1 1 1 1 1