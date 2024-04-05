# 90도 회전 구현
# list(map(list(zip(*tmp[::-1])))

n, q = map(int, input().split())
arr = []
for _ in range(2**n) :
    tmp = list(map(int, input().split()))
    arr.append(tmp)
Llist = list(map(int, input().split()))

map_size = 2**n
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

for _ in range(q) :
    L = Llist[_]

    # 2**L 단위로 쪼개기
    for i in range(0, map_size, 2**L) :
        for j in range(0, map_size, 2 ** L):
            tmp = []
            for t in range(i, i + 2**L) :
                tmp.append(arr[t][j:j + (2**L)])
            tmp = list(map(list, zip(*tmp[::-1])))
            # 회전된 tmp를 다시 arr 자리에 넣어주기
            for n in range(0, 2**L) :
                for m in range(0, 2**L) :
                    arr[i + n][j + m] = tmp[n][m]
    new_arr = [[0 for _ in range(map_size)] for __ in range(map_size)]
    # 주변의 얼음이 3개 이상이 아니라면 줄어들기
    for i in range(0, map_size) :
        for j in range(0, map_size) :
            cnt_ice = 0
            for d in range(4) :
                y = i + dy[d]
                x = j + dx[d]
                if (0 <= y < map_size and 0 <= x < map_size) :
                    if arr[y][x] > 0 :
                        cnt_ice += 1
            if (cnt_ice < 3) and (arr[i][j] > 0) :
                new_arr[i][j] = arr[i][j] - 1
            else :
                new_arr[i][j] = arr[i][j]

    for i in range(0, map_size):
        for j in range(0, map_size):
            arr[i][j] = new_arr[i][j]

maxV = max(max(arr))
maxLandSize = 0
currentSize = 1

# 섬 찾기!
from collections import deque


def bfs(map_size, arr, i, j, visited):
    # BFS를 위한 큐 초기화
    q = deque()
    q.append((i, j))
    visited[i][j] = True
    size = 0

    while q:
        y, x = q.popleft()
        size += 1  # 섬의 크기 증가

        # 상하좌우 방향 이동
        for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ny, nx = y + dy, x + dx
            if 0 <= ny < map_size and 0 <= nx < map_size and not visited[ny][nx] and arr[ny][nx] > 0:
                q.append((ny, nx))
                visited[ny][nx] = True

    return size


def find_largest_island(map_size, arr):
    visited = [[False for _ in range(map_size)] for __ in range(map_size)]
    largest_size = 0

    for i in range(map_size):
        for j in range(map_size):
            if arr[i][j] > 0 and not visited[i][j]:
                size = bfs(map_size, arr, i, j, visited)
                largest_size = max(largest_size, size)

    return largest_size

print(sum([sum(arr[i]) for i in range(map_size)]))
# visited = [[0 for _ in range(map_size)] for __ in range(map_size)]
# for i in range(0, map_size):
#     for j in range(0, map_size):
#         if arr[i][j] != 0 :
#             dfs(i, j, visited=visited)
#             currentSize = 1
# if maxLandSize == 1 :
#     print(0)
# else :
#     print(maxLandSize)

print(find_largest_island(map_size, arr))