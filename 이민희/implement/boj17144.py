r, c, t = map(int, input().split())
before_map = []
current_map = [[0 for _ in range(c)] for __ in range(r)]
ay = [0, 1, -1, 0]
ax = [1, 0, 0, -1]

cleaner = []

for _ in range(r) :
    before_map.append(list(map(int, input().split())))
    if (-1 in before_map[-1]) :
        cleaner.append(_)

# 확산 def
def blow() :
    global before_map, r, c, current_map
    for i in range(r) :
        for j in range(c) :
            if (before_map[i][j] == 0) :
                continue
            elif (before_map[i][j] == -1) :
                current_map[i][j] = -1
            else :
                cnt = 0
                value = before_map[i][j] // 5
                for dd in range(4) :
                    cy = i + ay[dd]
                    cx = j + ax[dd]
                    if (0 <= cy < r and 0 <= cx < c) :
                        if (before_map[cy][cx] != -1) :
                            cnt += 1
                            current_map[cy][cx] += value
                current_map[i][j] += before_map[i][j] - (value * cnt)

def wind() :
    global current_map, before_map
    # 위쪽 바람부터 먼저
    # 오른쪽으로 부는 바람
    a = current_map[cleaner[0]].pop(-1)
    current_map[cleaner[0]].insert(1, 0)
    # 위로 부는 바람
    tmp = [row[c - 1] for row in current_map[:(cleaner[0] + 1)]]
    tmp[-1] = a
    b = tmp.pop(0)
    for i, tt in enumerate(tmp) :
        current_map[i][c - 1] = tt
    # 왼쪽으로 부는 바람
    a = current_map[0].pop(0)
    current_map[0].insert(c - 2, b)
    # 아래로 부는 바람
    tmp = [row[0] for row in current_map[:(cleaner[0] + 1)]]
    tmp[0] = a
    for i in range(len(tmp) - 2) :
        current_map[i + 1][0] = tmp[i]

    # 아래쪽 바람 나중
    # 오른쪽으로 부는 바람
    a = current_map[cleaner[1]].pop(-1)
    current_map[cleaner[1]].insert(1, 0)
    # 아래로 부는 바람
    tmp = [row[c - 1] for row in current_map[cleaner[1]:]]
    tmp[0] = a
    b = tmp.pop(-1)
    for i, tt in enumerate(tmp) :
        current_map[(cleaner[1] + 1) + i][c - 1] = tt
    # 왼쪽으로 부는 바람
    a = current_map[r - 1].pop(0)
    current_map[r - 1].insert(c - 2, b)
    # 위로 부는 바람
    tmp = [row[0] for row in current_map[cleaner[1]:]]
    tmp[-1] = a
    tmp.pop(0)
    tmp.pop(0)
    for i in range(len(tmp)) :
        current_map[cleaner[1] + 1 + i][0] = tmp[i]
import copy
for _ in range(t) :
    current_map = [[0 for _ in range(c)] for __ in range(r)]
    blow()
    # print(sum(list(sum(row) for row in current_map)) + 2)
    wind()
    # print(sum(list(sum(row) for row in current_map)) + 2)

    before_map = copy.deepcopy(current_map)

print(sum(list(sum(row) for row in before_map)) + 2)
                

# list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# print(list[:2])
