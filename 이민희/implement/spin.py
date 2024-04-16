N, M = map(int, input().split())
numMap = [[0 for _ in range(N)] for __ in range(N)]

num = 0
limitLen = 1
curntLen = 0
curntDir = 0
flag = 0

def findSerial(rocks) :
    idx = 0
    ans = []
    while idx != len(rocks) :
        if (idx + 3 < len(rocks) and rocks[idx] == rocks[idx + 1] and rocks[idx] == rocks[idx + 2] and rocks[idx] == rocks[idx + 3]) :
            # count 몇개가 같은지!
            value = rocks[idx]
            cnt = 1
            while True :
                if (idx + cnt < len(rocks) and value == rocks[idx + cnt]) :
                    cnt += 1
                else :
                    break
            for i in range(1, cnt + 1) : ans.append(idx + i)
            idx += cnt
        else :
            idx += 1
    return ans

def countRocks(rocks) :
    idx = 0
    ans = []
    while idx != len(rocks):
        if (idx + 1 < len(rocks) and rocks[idx] == rocks[idx + 1]) :
            # count 몇개가 같은지!
            value = rocks[idx]
            cnt = 1
            while True:
                if (idx + cnt < len(rocks) and value == rocks[idx + cnt]):
                    cnt += 1
                else:
                    break
            ans.append(cnt)
            ans.append(rocks[idx])
            idx += cnt
        else:
            ans.append(1)
            ans.append(rocks[idx])
            idx += 1
    return ans


dy = [0, 1, 0, -1]
dx = [-1, 0, 1, 0]
y = N // 2
x = (N // 2) + 1
while num != (N ** 2) :
    # 현재 위치에 num 찍기
    y = dy[curntDir] + y
    x = dx[curntDir] + x
    numMap[y][x] = num

    if (curntLen == limitLen) :
        curntDir += 1
        curntDir %= 4
        curntLen = 0
        flag += 1
        if (flag == 2) :
            flag = 0
            limitLen += 1
    num += 1
    curntLen += 1

arr = []
instruction = []
for _ in range(N) :
    tmp = list(map(int, input().split()))
    arr.append(tmp)
for _ in range(M) :
    a, b = map(int, input().split())
    instruction.append([a, b])
num = 0
limitLen = 1
curntLen = 0
curntDir = 0
flag = 0

y = N // 2
x = (N // 2) + 1

answer = 0
for instr in instruction :
    rock = []
    y = N // 2
    x = (N // 2) + 1
    num = 0
    limitLen = 1
    curntLen = 0
    curntDir = 0
    flag = 0
    while num != (N ** 2) :
        # 현재 위치에 num 찍기
        y = dy[curntDir] + y
        x = dx[curntDir] + x
        if arr[y][x] != 0 :
            rock.append(arr[y][x])

        if (curntLen == limitLen) :
            curntDir += 1
            curntDir %= 4
            curntLen = 0
            flag += 1
            if (flag == 2) :
                flag = 0
                limitLen += 1
        num += 1
        curntLen += 1

    # 파괴할 부분을 잡는다.
    ddy = [-1, 1, 0, 0]
    ddx = [0, 0, -1, 1]
    y = N // 2
    x = N // 2

    deleteIdx = []
    for i in range(1, instr[1] + 1) :
        yy = y + (ddy[instr[0] - 1] * i)
        xx = x + (ddx[instr[0] - 1] * i)
        if (0 <= yy < N and 0 <= xx < N) :
            deleteIdx.append(numMap[yy][xx])
    deleteIdx = deleteIdx[::-1]
    for d in deleteIdx :
        if (d - 1 < len(rock)) :
            rock.pop(d - 1)

    while True :
        # 같은 숫자의 연속된 4개의 구슬 폭발
        serials = findSerial(rock)
        if len(serials) == 0 :
            break
        serials = serials[::-1]
        for d in serials :
            # 1×(폭발한 1번 구슬의 개수) + 2×(폭발한 2번 구슬의 개수) + 3×(폭발한 3번 구슬의 개수)
            answer += rock[d - 1]
            rock.pop(d - 1)

    rock = countRocks(rock)
    # arr에 다시 그리기
    arr = [[0 for i in range(N)] for i in range(N)]
    rock.insert(0, 0)
    rockIdx = 0
    num = 0
    limitLen = 1
    curntLen = 0
    curntDir = 0
    flag = 0

    y = N // 2
    x = (N // 2) + 1
    while rockIdx < N ** 2 and rockIdx < len(rock):
        # 현재 위치에 num 찍기
        y = dy[curntDir] + y
        x = dx[curntDir] + x
        arr[y][x] = rock[rockIdx]

        if (curntLen == limitLen):
            curntDir += 1
            curntDir %= 4
            curntLen = 0
            flag += 1
            if (flag == 2):
                flag = 0
                limitLen += 1
        num += 1
        curntLen += 1
        rockIdx += 1
print(answer)