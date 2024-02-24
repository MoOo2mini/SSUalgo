n, m = map(int, input().split())
arr = []
cctvs = []
wall_cnt = 0
for _ in range(n) :
    arr.append(list(map(int, input().split())))
    for i in range(m) :
        if (1 <= arr[_][i] <= 5) :
            cctvs.append([arr[_][i], _, i])
        elif (arr[_][i] == 6) :
            wall_cnt += 1
# 상 하 좌 우
for_1 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
for_2 = [[1, 1, 0, 0], [0, 0, 1, 1]]
for_3 = [[1, 0, 1, 0], [0, 1, 0, 1], [1, 0, 0, 1], [0, 1, 1, 0]]
for_4 = [[0, 1, 1, 1], [1, 0, 1, 1], [1, 1, 0, 1], [1, 1, 1, 0]]
for_5 = [[1, 1, 1, 1]]
fors = [for_1, for_2, for_3, for_4, for_5]
visited = [[0] * m for _ in range(n)]
def check(cctv_dir) :
    global visited
    visited = [[0] * m for _ in range(n)]
    result = 0
    for i in range(len(cctv_dir)) :
        _, y, x = cctvs[i]
        if (visited[y][x] == 0) :
            visited[y][x] = 1
            result += 1
        direct = cctv_dir[i]

        # 상으로 가야한다면.
        if (direct[0]) :
            idx = 1
            while (True) :
                yy = y - idx
                if (0 <= yy < n) :
                    if (arr[yy][x] != 6) :
                        if (visited[yy][x] != 1) :
                            visited[yy][x] = 1
                            result += 1
                        idx += 1
                    else :
                        break
                else :
                    break
        if (direct[1]) :
            idx = 1
            while (True) :
                yy = y + idx
                if (0 <= yy < n) :
                    if (arr[yy][x] != 6) :
                        if (visited[yy][x] != 1) :
                            visited[yy][x] = 1
                            result += 1
                        idx += 1
                    else :
                        break
                else :
                    break
        if (direct[2]) :
            idx = 1
            while (True) :
                xx = x - idx
                if (0 <= xx < m) :
                    if (arr[y][xx] != 6) :
                        if (visited[y][xx] != 1) :
                            visited[y][xx] = 1
                            result += 1
                        idx += 1
                    else :
                        break
                else :
                    break
        if (direct[3]) :
            idx = 1
            while (True) :
                xx = x + idx
                if (0 <= xx < m) :
                    if (arr[y][xx] != 6) :
                        if (visited[y][xx] != 1) :
                            visited[y][xx] = 1
                            result += 1
                        idx += 1
                    else :
                        break
                else :
                    break
    return result

maxV = 0
def dfs(idx, cctv_dir) :
    global fors, cctvs, maxV

    if (len(cctv_dir) == len(cctvs)) :
        maxV = max(maxV, check(cctv_dir))
        return

    for i in range(5) :
        if (cctvs[idx][0] == (i + 1)) :
            for f in fors[i] :
                cctv_dir.append(f)
                dfs(idx + 1, cctv_dir)
                cctv_dir.pop()
            break

dfs(0, [])
print((n * m) - maxV - wall_cnt)