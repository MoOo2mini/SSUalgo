# 4 4 1
# 0 1 4 4
# 8 0 10 13
# 8 0 11 26
# 0 0 0 0
n, m, k = map(int, input().split())
arr = []

for _ in range(m) :
    tmp = list(map(int, input().split()))
    tmp = [[tmp[i], 0] for i in range(len(tmp))]
    arr.append(tmp)

second = 0
while second != k :
    second += 1
    # 공격자 선정
    minValue = 5001
    attackers = []
    for i in range(n) :
        for j in range(m) :
            if arr[i][j][0] != 0:
                minValue = min(arr[i][j][0], minValue)
    for i in range(n) :
        for j in range(m) :
            if arr[i][j][0] == minValue :
                attackers.append([i, j, arr[i][j][0], arr[i][j][1], i + j])
    attackers = sorted(attackers, key=lambda x : (x[2], -x[3], -x[4], -x[0]))
    attackersy, attackersx, score, recentAttack, _ = attackers[0]
    arr[attackersy][attackersx][0] += (n + m)

    # 자신을 제외한 가장 강한 포탑 찾기
    maxValue = 0
    attacked = []
    for i in range(n) :
        for j in range(m) :
            if arr[i][j][0] != 0 :
                if not (i == attackersy and j == attackersx):
                    maxValue = max(arr[i][j][0], maxValue)
    for i in range(n) :
        for j in range(m) :
            if arr[i][j][0] == maxValue :
                attacked.append([i, j, arr[i][j][0], arr[i][j][1], i + j])
    attacked = sorted(attacked, key=lambda x : (-x[2], x[3], x[4], x[0]))
    yy, xx, _, _, _ = attacked[0]

    # 레이저
    dy = [0, 1, 0, -1]
    dx = [1, 0, -1, 0]
    # 레이저 가능 여부
    useLazer = False
    def bfs(crnY, crnX, visited, dstY, dstX) :
        global arr
        from collections import deque
        q = deque()
        q.append([[crnY, crnX], []])

        while len(q) != 0 :
            yx, route = q.popleft()
            crnY, crnX = yx[0], yx[1]
            if (crnX == dstX and crnY == dstY):
                arr[yy][xx][0] -= arr[attackersy][attackersx][0]
                for rr in range(len(route) - 1):  # 경로 추적
                    ry = route[rr][0]
                    rx = route[rr][1]
                    arr[ry][rx][0] -= (arr[attackersy][attackersx][0] // 2)
                return True
            for idx in range(4) :
                y = crnY + dy[idx]
                y %= n
                x = crnX + dx[idx]
                x %= m
                if (0 <= y < n and 0 <= x < m) and visited[y][x] == 0 and arr[y][x][0] != 0 :
                    visited[y][x] = visited[crnY][crnX] + 1
                    tmp_route = route[:]
                    tmp_route.append((y, x))
                    q.append([[y, x], tmp_route])
        return False
    saveMap = []
    def dfs(crnY, crnX, visited, dstY, dstX, leadMap) :
        global useLazer
        if (crnX == dstX and crnY == dstY) :
            if len(saveMap) == 0 :
                useLazer = True
                tmp = [visited[i][:] for i in range(len(visited))]
                saveMap.append(tmp)
            return
        elif len(saveMap) != 0 :
            return
        for idx in range(4) :
            y = crnY + dy[idx]
            y %= n
            x = crnX + dx[idx]
            x %= m
            if (0 <= y < n and 0 <= x < m) and visited[y][x] == 0 and leadMap[y][x] == leadMap[crnY][crnX] + 1:
                if (arr[y][x][0] != 0) :
                    visited[y][x] = visited[crnY][crnX] + 1
                    dfs(y, x, visited, dstX, dstY, leadMap)
                    visited[y][x] = 0


    visited = [[0 for _ in range(m)] for _ in range(n)]
    visited[attackersy][attackersx] = 1
    useLazer = bfs(attackersy, attackersx, visited, yy, xx)
    #
    # visited = [[0 for _ in range(m)] for _ in range(n)]
    # visited[attackersy][attackersx] = 1
    # dfs(attackersy, attackersx, visited, yy, xx, leadMap)


    if not useLazer : # 포탄
        destroyed = [[0 for _ in range(m)] for _ in range(n)]
        destroyed[attackersy][attackersx] = 1
        destroyed[yy][xx] = 1

        ddy = [-1, -1, -1, 0, 0, 1, 1, 1]
        ddx = [-1, 0, 1, -1, 1, -1, 0, 1]
        for idx in range(8) :
            y = yy + ddy[idx]
            x = xx + ddx[idx]
            y %= n
            x %= m
            if (arr[y][x][0] > 0) :
                arr[y][x][0] -= arr[attackersy][attackersx][0] // 2
                destroyed[y][x] = 1
                if arr[y][x][0] < 0:
                    arr[y][x][0] = 0
        arr[yy][xx][0] -= arr[attackersy][attackersx][0]
        if (arr[yy][xx][0] < 0) :
            arr[yy][xx][0] = 0
        arr[attackersy][attackersx][1] = second
        for i in range(n) :
            for j in range(m) :
                if destroyed == 0 and arr[i][j][0] != 0 :
                    arr[i][j][0] += 1
    #
    # print(second, "번째 턴")
    # print(*arr, sep='\n')
    # print('++++++++++++')
maxValue = 0
for i in range(n) :
    for j in range(m) :
        maxValue = max(arr[i][j][0], maxValue)
print(maxValue)
