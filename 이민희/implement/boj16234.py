n, L, R = map(int, input().split())

arr = []
for _ in range(n) :
    arr.append(list(map(int, input().split())))

def bfs(i, j) :
    global visited
    global n, L, R
    q = []
    q.append([i, j])
    direction = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    visit_set = set()
    visit_cnt = 1
    visit_add = arr[i][j]
    visit_set.add(tuple([i, j]))
    while (q) :
        r, c = q.pop(0)
        for dd in direction :
            if (0 <= r + dd[0] < n and 0 <= c + dd[1] < n) :
                if (visited[r + dd[0]][c + dd[1]] == 0) :
                    tmp = abs(arr[r][c] - arr[r + dd[0]][c + dd[1]])
                    if (L <= tmp and tmp <= R) :
                        visited[r + dd[0]][c + dd[1]] = 1
                        q.append([r + dd[0], c + dd[1]])
                        visit_cnt += 1
                        visit_add += arr[r + dd[0]][c + dd[1]]
                        visit_set.add(tuple([r + dd[0], c + dd[1]]))
    if (visit_cnt >= 2) :
        visit_mean = visit_add // visit_cnt
        for yx in visit_set :
            yy = yx[0]
            xx = yx[1]
            arr[yy][xx] = visit_mean
        return 1
    else :
        return 0

real = 0
while (True) :
    result = 0
    visited = [[0] * n for _ in range(n)]

    for i in range(n) :
        for j in range(n) :
            if (visited[i][j] == 0) :
                visited[i][j] = 1
                result += bfs(i, j)
    if (result == 0) :
        break
    else :
        real += 1

print(real)