# 4 3 5
# 0 0 1 0
# 0 0 1 0
# 1 1 0 1
# 0 0 2 0
# 1 2 2 1 5
# 2 1 2 1 1
# 3 2 1 2 3
# 1 2
# 2 1
# 3 3
# 3 3
# 2 1
# 체스판 밖도 벽으로 간주한다.
# 기사는 체력이 0이 되면 사라진다.--> dict에서 없애지는 않음

L, N, Q = map(int, input().split())
arrMap = []
knights = {}
instructions = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
originScore = {}

# 기사 이동
def move(knightIdx, direction, visited):
    global knightMap, arrMap, tmpKnights, knights
    startR = 0
    endR = 0
    startC = 0
    endC = 0
    r, c, h, w, k = knights[knightIdx]
    visited[knightIdx  - 1] = 1
    # 끝에 -1 들어가는 범위 감안해서 잡기
    if direction == 0:
        startR = r - 1
        endR = r
        startC = c
        endC = c + w
    elif direction == 1:
        startR = r
        endR = r + h
        startC = c + w
        endC = c + w + 1
    elif direction == 2:
        startR = r + h
        endR = r + h + 1
        startC = c
        endC = c + w
    elif direction == 3:
        startR = r
        endR = r + h
        startC = c - 1
        endC = c

    for i in range(startR, endR):
        for j in range(startC, endC):
            # if 범위 내 :
            #     if arrMap에서 벽 :
            #         return False
            #     if knightMap에서 다른 기사 :
            #         flag = move(다른 기사 번호, direction) # 방향 유지
            #         if flag :
            #             continue
            #         else :
            #             return False
            if (0 <= i < L and 0 <= j < L) :
                if arrMap[i][j] == 2 :
                    return False
                if knightMap[i][j] != 0 and knightMap[i][j] != knightIdx :
                    if (visited[knightMap[i][j] - 1] == 0) :
                        flag = move(knightMap[i][j], direction, visited) # 방향 유지
                        if flag :
                            continue
                        else :
                            return False
            else :
                return False
    # tmpKnights의 r, c 값을 direction에 맞게 조절
    r, c, h, w, k = tmpKnights[knightIdx]
    r += dy[direction]
    c += dx[direction]

    tmpKnights[knightIdx] = [r, c, h, w, k]
    return True

def attacked(knightIdx, direction):
    global knightMap, arrMap, tmpKnights, knights
    startR = 0
    endR = 0
    startC = 0
    endC = 0
    r, c, h, w, k = knights[knightIdx]
    answer = 0

    # 끝에 -1 들어가는 범위 감안해서 잡기
    if direction == 0:
        startR = r
        endR = r + 1
        startC = c
        endC = c + w
    elif direction == 1:
        startR = r
        endR = r + h
        startC = c + w - 1
        endC = c + w
    elif direction == 2:
        startR = r + h - 1
        endR = r + h
        startC = c
        endC = c + w
    elif direction == 3:
        startR = r
        endR = r + h
        startC = c
        endC = c + 1

    # for i in range(startR, endR):
    #     for j in range(startC, endC):
    #         if arrMap[i][j] == 1 :
    #             answer += 1

    for i in range(r, r + h) :
        for j in range(c, c + w) :
            if arrMap[i][j] == 1:
                answer += 1
    return answer

for _ in range(L) :
    tmp = list(map(int, input().split()))
    arrMap.append(tmp)
for i in range(1, N + 1) :
    tmp = list(map(int, input().split()))
    knights[i] = [tmp[0] - 1, tmp[1] - 1, tmp[2], tmp[3], tmp[4]]
    originScore[i] = tmp[4]
for _ in range(Q) :
    tmp = list(map(int, input().split()))
    instructions.append(tmp)
goneKnight = [0 for i in range(N)]

for q in range(Q) :
    knightIdx, direction = instructions[q]

    # 사라진 기사에 대한 명령은 무시
    if knights[knightIdx][4] <= 0 :
        continue

    # 기사들의 정보에 따라 기사들을 그린다.
    # 사라진 기사라면 그려주지 않음.
    knightMap = [[0 for _ in range(L)] for __ in range(L)]
    for idx in range(1, N + 1) :
        r, c, h, w, k = knights[idx]
        if k <= 0 :
            continue
        for i in range(r, r + h) :
            for j in range(c, c + w) :
                knightMap[i][j] = idx

    tmpKnights = {}
    for i in range(1, N + 1 ): tmpKnights[i] = knights[i]
    visited = [0 for _ in range(N)]

    movingTF = move(knightIdx, direction, visited)
    if movingTF :
        # tmpKnights를 knights에 반영
        for i in range(1, N + 1): knights[i] = tmpKnights[i]

        # 반영 후 타격 입히기
        for ii, v in enumerate(visited) :
            if v == 1 and ii + 1 != knightIdx :
                # attacked는 기사의
                attackedScore = attacked(ii + 1, direction)
                knights[ii + 1][4] -= attackedScore
                if (knights[ii + 1][4] <= 0) :
                    knights[ii + 1][4] = 0
                    goneKnight[ii] = 1
        # 사라진 기사는 map에서 0으로 만든다.
        # 기사들의 정보에 따라 기사들을 그린다.
        knightMap = [[0 for _ in range(L)] for __ in range(L)]
        for idx in range(1, N + 1):
            if goneKnight[idx - 1] == 1 :
                continue
            r, c, h, w, k = knights[idx]
            for i in range(r, r + h):
                for j in range(c, c + w):
                    knightMap[i][j] = idx

ans = 0
for i in range(1, N + 1) :
    if knights[i][4] > 0 :
        ans += originScore[i] - knights[i][4]
print(ans)

# 5 5 5
# 0 0 1 1 2
# 1 0 1 0 1
# 0 1 0 1 2
# 1 1 1 1 1
# 1 0 1 1 1
# 1 1 2 2 2
# 3 1 2 1 12
# 5 4 1 2 16
# 3 3 2 2 5
# 4 5 1 1 19
# 3 0
# 5 3
# 4 0
# 2 1
# 3 1
