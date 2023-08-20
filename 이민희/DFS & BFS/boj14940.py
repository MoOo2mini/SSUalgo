import queue

xx = [0, 0, 1, -1]
yy = [1, -1, 0, 0]

lst = []

a, b = map(int, input().split())
answerMap = [[0 for i in range(b)] for j in range(a)]
visited = [[0 for i in range(b)] for j in range(a)]

x = 0
y = 0
for i in range(a) :
    tmp = list(map(int, input().split()))
    if (2 in tmp) :
        y = i
        x = tmp.index(2)
    lst.append(tmp)

q = queue.Queue()

q.put([y, x])
visited[y][x] = 1

while not q.empty() :
    front = q.get()

    for i in range(4) :
        ny = front[0] + yy[i]
        nx = front[1] + xx[i]
        # 오른쪽 왼쪽 위 아래가 있을 때 범위에 들어오는지

        if (ny >= a or ny < 0) :
            continue
        if (nx >= b or nx < 0) :
            continue

        if (lst[ny][nx] == 1 and visited[ny][nx] == 0) :
            answerMap[ny][nx] += answerMap[front[0]][front[1]] + 1
            q.put([ny, nx])
            visited[ny][nx] = 1

for i in range(a) :
    for j in range(b) :
        if (visited[i][j] == 0 and lst[i][j] != 0) :
            answerMap[i][j] = -1
    
for i in answerMap :
    print(*i)

