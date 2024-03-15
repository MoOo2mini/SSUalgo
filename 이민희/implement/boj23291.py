n, k = map(int, input().split())
arr = [list(map(int, input().split()))]
answer = 0
while True :
    # 물고기 수가 가장 적은 어항에 물고기를 1마리씩 넣는다.
    minV = min(arr[0])
    while True :
        try :
            idx = arr[0].index(minV)
            arr[0][idx] += 1
        except :
            break

    # 어항 쌓기 - 왼쪽 어항을 오른쪽 어항 위에 올려놓는다.
    tmp = arr[0].pop(0)
    arr.insert(0, [tmp])

    while True :
        # 두개 이상 쌓여있는 어항을 공중부양시킨 다음 시계방향 90도로 회전
        # 1) 두개 이상 어항 공중부양 # 가로: len(arr[0]), 세로: len(arr)
        # print(*arr, sep='\n')
        from copy import deepcopy as dc
        tmp = arr[-1][len(arr[0]):]
        arr[-1] = arr[-1][0:len(arr[0])]

        bowl = dc(arr)

        # print(bowl)
        # print(tmp)

        # 시계 방향으로 90도 회전
        aa = []
        bowl = bowl[::-1]
        for i in range(len(bowl[0])) :
            aa.append([bowl[j][i] for j in range(len(bowl))])
        
        aa.append(tmp)
        arr = dc(aa)
        # print(aa)
        # print(len(arr), len(tmp) - len(arr[0]))
        if (len(arr) > len(tmp) - len(arr[0])) :
            break

    # print(arr)

    # 개체 수 조절

    visited = []

    for j in range(len(arr) - 1) :
        visited.append([0 for i in range(len(arr[0]))])
    visited.append([0 for _ in range(len(arr[-1]))])
    tmp = dc(visited)

    # 오른쪽, 아래만 확인
    for i in range(len(arr)) :
        row = arr[i]
        for j in range(len(row)) :
            # 오른쪽 확인
            if not (j + 1 == len(row)) :
                if (True) :
                    visited[i][j] = 1
                    visited[i][j + 1] = 1
                    d = (abs(arr[i][j] - arr[i][j + 1])) // 5
                    if (d > 0) :
                        if (arr[i][j] > arr[i][j + 1]) :
                            tmp[i][j] -= d
                            tmp[i][j + 1] += d
                        else :
                            tmp[i][j + 1] -= d
                            tmp[i][j] += d
            # 아래쪽 확인
            if not (i == len(arr) - 1) :
                if (True) :
                    visited[i][j] = 1
                    visited[i + 1][j] = 1
                    d = (abs(arr[i][j] - arr[i + 1][j])) // 5
                    if (d > 0) :
                        if (arr[i][j] > arr[i + 1][j]) :
                            tmp[i][j] -= d
                            tmp[i + 1][j] += d
                        else :
                            tmp[i + 1][j] -= d
                            tmp[i][j] += d

    # print(tmp)
    for i in range(len(arr)) :
        for j in range(len(arr[i])) :
            arr[i][j] += tmp[i][j]

    tmp = arr[-1][len(arr[0]):]
    arr[-1] = arr[-1][0:len(arr[0])]

    bowl = dc(arr)

    # print(bowl)
    # print(tmp)

    # 시계 방향으로 90도 회전
    aa = []
    bowl = bowl[::-1]
    for i in range(len(bowl[0])) :
        aa.append([bowl[j][i] for j in range(len(bowl))])

    # print(aa)
    bb = []
    for i in aa :
        for j in i :
            bb.append(j)
    for i in tmp :
        bb.append(i)
    arr = dc(bb)

    aa = arr[0:(len(arr) // 2)]
    aa = aa[::-1]
    bb = arr[(len(arr) // 2):]

    arr = [aa, bb]
    # print(arr)
    aa = []
    bb = []
    for i in range(len(arr)) :
        aa.append(arr[i][0:(len(arr[i]) // 2)])
        bb.append(arr[i][len(arr[i])//2:])
    aa = aa[::-1]

    arr = []
    for i in aa :
        i = i[::-1]
        arr.append(i)
    for i in bb :
        arr.append(i)

    # 다시 물고기 조절
    # 개체 수 조절

    visited = []

    for j in range(len(arr) - 1) :
        visited.append([0 for i in range(len(arr[0]))])
    visited.append([0 for _ in range(len(arr[-1]))])
    tmp = dc(visited)

    # 오른쪽, 아래만 확인
    for i in range(len(arr)) :
        row = arr[i]
        for j in range(len(row)) :
            # 오른쪽 확인
            if not (j + 1 == len(row)) :
                if (True) :
                    visited[i][j] = 1
                    visited[i][j + 1] = 1
                    d = (abs(arr[i][j] - arr[i][j + 1])) // 5
                    if (d > 0) :
                        if (arr[i][j] > arr[i][j + 1]) :
                            tmp[i][j] -= d
                            tmp[i][j + 1] += d
                        else :
                            tmp[i][j + 1] -= d
                            tmp[i][j] += d
            # 아래쪽 확인
            if not (i == len(arr) - 1) :
                if (True) :
                    visited[i][j] = 1
                    visited[i + 1][j] = 1
                    d = (abs(arr[i][j] - arr[i + 1][j])) // 5
                    if (d > 0) :
                        if (arr[i][j] > arr[i + 1][j]) :
                            tmp[i][j] -= d
                            tmp[i + 1][j] += d
                        else :
                            tmp[i + 1][j] -= d
                            tmp[i][j] += d

    # print(tmp)
    for i in range(len(arr)) :
        for j in range(len(arr[i])) :
            arr[i][j] += tmp[i][j]
    tmp = arr[-1][len(arr[0]):]
    arr[-1] = arr[-1][0:len(arr[0])]

    bowl = dc(arr)

    # print(bowl)
    # print(tmp)

    # 시계 방향으로 90도 회전
    aa = []
    bowl = bowl[::-1]
    for i in range(len(bowl[0])) :
        aa.append([bowl[j][i] for j in range(len(bowl))])

    # print(aa)
    bb = []
    for i in aa :
        for j in i :
            bb.append(j)
    for i in tmp :
        bb.append(i)
    arr = dc(bb)
    # print(arr)

    if (max(arr) - min(arr) <= k) :
        break
    else :
        answer += 1
        arr = [arr]

print(answer + 1)