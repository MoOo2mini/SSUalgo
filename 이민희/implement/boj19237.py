n, m, k = map(int, input().split())
# n: 격자의 크기
# m: 상어의 개수
# k: 냄새의 지속 되는 시간(초)

arr = []
park = []
for _ in range(n) :
    tmp = list(map(int, input().split()))
    for i in range(n) :
        if (tmp[i] != 0) :
            tmp[i] = [tmp[i], k]
        else :
            tmp[i] = [tmp[i], 0]
    arr.append(tmp)

final = False
# 각 상어의 방향이 들어온다.
shark_dir = {}
tmp = list(map(int, input().split()))
for i in range(1, m + 1) :
    shark_dir[i] = tmp[i - 1]

direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]

rank = []
for i in range(m) :
    tmparr = []
    for _ in range(4) :
        tmp = list(map(int, input().split()))
        tmparr.append(tmp)
    rank.append(tmparr)
from copy import deepcopy as dc
tmparr = dc(arr)

count = 0

while not final :
    count += 1

    for i in range(n) :
        for j in range(n) :
            if (arr[i][j][0] != 0 and arr[i][j][1] != k) :
                if (arr[i][j][1] == 1) :
                    # 흔적 제거
                    arr[i][j] = [arr[i][j][0], 0]
                elif (arr[i][j][1] == 0) :
                    # 흔적 제거
                    arr[i][j] = [0, 0]
                else :
                    arr[i][j] = [arr[i][j][0], arr[i][j][1] - 1]
    tmparr = dc(arr)
    for i in range(n) :
        for j in range(n) :
            if (arr[i][j][0] != 0 and arr[i][j][1] == k) :
                # 현재 상어의 dir 얻기
                currentDir = shark_dir[arr[i][j][0]]
                priorityList = rank[arr[i][j][0] - 1][currentDir - 1]
                flag = False
                for dd in priorityList :
                    y, x = direction[dd - 1]
                    cy = i + y
                    cx = j + x
                    if not (0 <= cy < n and 0 <= cx < n) :
                        continue
                    if (arr[cy][cx][0] == 0) :
                        # 빈칸으로 이동하기
                        # 자신이 있던 공간에 흔적 남기기
                        tmparr[i][j] = [arr[i][j][0], k - 1]
                        if (tmparr[cy][cx][0] == 0 or tmparr[i][j][0] < tmparr[cy][cx][0]) :
                            if (tmparr[i][j][0] < tmparr[cy][cx][0]) :
                                park.append(tmparr[cy][cx][0])
                            tmparr[cy][cx] = arr[i][j]
                            shark_dir[arr[i][j][0]] = dd
                        else :
                            # 내쫓긴 상어
                            park.append(arr[i][j][0])
                            # if (len(park) == m - 1) :
                            #     final = True
                            #     break
                        flag = True
                        break

                if (flag) :
                    continue
                for dd in priorityList :
                    y, x = direction[dd - 1]
                    cy = i + y
                    cx = j + x
                    if not (0 <= cy < n and 0 <= cx < n) :
                        continue
                    if (arr[cy][cx][0] == arr[i][j][0]) :
                        # 이동하기
                        # 자신이 있던 공간에 흔적 남기기
                        tmparr[i][j] = [arr[i][j][0], k - 1]
                        # 자신 옮기기 => 만약 옮기려는데, 자신보다 작은 수가 있다면 없어져버리기.
                        if (tmparr[cy][cx][0] == 0 or tmparr[i][j][0] <= tmparr[cy][cx][0]) :
                            if (tmparr[i][j][0] < tmparr[cy][cx][0]) :
                                park.append(tmparr[cy][cx][0])
                            tmparr[cy][cx] = arr[i][j]
                            shark_dir[arr[i][j][0]] = dd
                        else :
                            # 내쫓긴 상어
                            park.append(arr[i][j][0])
                            # if (len(park) == m - 1) :
                            #     final = True
                            #     break
                        break
    if (len(park) == m - 1 or count > 1000) :
        final = True
        break
    arr = dc(tmparr)     
if count > 1000 :
    print(-1)               
else :
    print(count)