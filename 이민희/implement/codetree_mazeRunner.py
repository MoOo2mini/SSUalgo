# 5 3 8
# 0 0 0 0 1
# 9 2 2 0 0
# 0 1 0 1 0
# 0 0 0 1 0
# 0 0 0 0 0
# 1 3
# 3 1
# 3 5
# 3 3
n, m, k = map(int, input().split())
arr = []
participants = []
for _ in range(n) :
    tmp = list(map(int, input().split()))
    arr.append(tmp)
for _ in range(m) :
    a, b = map(int, input().split())
    participants.append([a - 1, b - 1])
exitY, exitX = map(int, input().split())
exitX -= 1
exitY -= 1
movingCnt = 0 # 회전은 이동 횟수에 들어가지 않음.

for kk in range(k) :
    if len(participants) == 0 :
        break
    # 참가자 움직임
    dy = [1, -1, 0, 0]
    dx = [0, 0, -1, 1]
    tmp = []
    for idx, person in enumerate(participants) :
        cy, cx = person[:]
        moved = False
        for dd in range(4) :
            y = dy[dd] + cy
            x = dx[dd] + cx

            if (0 <= y < n and 0 <= x < n) :
                if (exitY == y and exitX == x) :
                    movingCnt += 1
                    moved = True
                    break
                if (arr[y][x] == 0) :
                    crnDistance = abs(cy - exitY) + abs(cx - exitX)
                    nxtDistance = abs(y - exitY) + abs(x - exitX)
                    if (crnDistance > nxtDistance) :
                        tmp.append([y, x])
                        movingCnt += 1
                        moved = True
                        break
        if not moved :
            tmp.append([cy, cx])
    participants = [tmp[i][:] for i in range(len(tmp))]
    if len(participants) == 0 :
        break
    # 미로 회전 & 내구성 1 깎임. 회전하지 않는 것은 깎이지 않음.

    # 사각형 후보 구하기
    squareCandidate = []
    for person in participants :
        # 사람과 출구가 가로 방향인지, 세로 방향인지 확인
        cy, cx = person[:]
        rowDis = abs(cx - exitX)
        colDis = abs(cy - exitY)
        if (rowDis >= colDis) : # 가로 방향으로 더 크면
            distance = abs(cx - exitX)
            dis = distance
            Ymax = max(cy, exitY)
            Ymin = min(cy, exitY)
            # cy - distance ~ cy + distance
            for d in range(Ymax - distance, Ymin + 1) :
                if (0 <= d < n and 0 <= d + distance < n) :
                    squareCandidate.append([dis, d, min(cx, exitX), d + distance, max(cx, exitX)])
        elif (rowDis < colDis) :
            distance = abs(cy - exitY)
            dis = distance
            Xmax = max(cx, exitX)
            Xmin = min(cx, exitX)
            # cy - distance ~ cy + distance
            for d in range(Xmax - distance, Xmin + 1):
                if (0 <= d < n and 0 <= d + distance < n) :
                    squareCandidate.append([dis, min(cy, exitY), d, max(cy, exitY), d + distance])
    squareCandidate = sorted(squareCandidate, key=lambda x : (x[0], x[1], x[2]))
    square = squareCandidate[0]

    # 회전하기
    # arr 회전
    distance, uy, ux, dy, dx = square
    tmp = [arr[i][ux : ux + (distance + 1)] for i in range(uy, uy + (distance + 1))]
    tmp = list(map(list, zip(*tmp[::-1])))
    for i in range(len(tmp)) :
        for j in range(len(tmp[i])) :
            if tmp[i][j] != 0 :
                tmp[i][j] -= 1
    for i in range(0, distance + 1) :
        for j in range(0, distance + 1) :
            arr[i + uy][j + ux] = tmp[i][j]

    # 사람 회전 + 출구 회전
    personMap = [[0 for i in range(n)] for _ in range(n)]
    personMap[exitY][exitX] = -1
    for person in participants :
        cy, cx = person[:]
        personMap[cy][cx] += 1
    tmp = [personMap[i][ux : ux + (distance + 1)] for i in range(uy, uy + (distance + 1))]
    tmp = list(map(list, zip(*tmp[::-1])))
    for i in range(0, distance + 1):
        for j in range(0, distance + 1):
            personMap[i + uy][j + ux] = tmp[i][j]
    # participants 재구성
    participants = []
    for i in range(n) :
        for j in range(n) :
            if (personMap[i][j] > 0) :
                for _ in range(personMap[i][j]) :
                    participants.append([i, j])
            elif (personMap[i][j] != 0) :
                exitY = i
                exitX = j

print(movingCnt)
print(exitY + 1, exitX + 1, sep=' ')