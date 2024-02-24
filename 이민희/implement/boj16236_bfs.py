from collections import deque

N = int(input())
space = [list(map(int, input().split())) for _ in range(N)]

dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]

pos = []
for i in range(N):
    for j in range(N):
        if space[i][j] == 9:
            pos.append(i)
            pos.append(j)

cnt = 0

# 3. 가까운 먹이를 찾는 탐색 문제이기 때문에 `BFS`를 생각해 볼 수 있다.
# 4. BFS를 사용할 시 입력으로는 현재 아기 상어의 위치를 생각할 수 있고,
# 	 출력으로는 후보를 리스트를 반환 해야한다.
def bfs(x, y):
    visited = [[0]*N for _ in range(N)]
    queue = deque([[x,y]])
    cand = []

    visited[x][y] = 1

    while queue:
        i, j = queue.popleft()

        for idx in range(4):
            ii, jj = i + dx[idx] , j + dy[idx]

            if 0 <= ii and ii < N and 0 <= jj and jj < N and visited[ii][jj] == 0:
				# 5. 간선은 상하 좌우지만 조건에 따라서 움직이기 때문에 조건을 상세하여야한다.
                if space[x][y] > space[ii][jj] and space[ii][jj] != 0:
                    visited[ii][jj] =  visited[i][j] + 1
                    cand.append((visited[ii][jj] - 1, ii, jj))
                elif space[x][y] == space[ii][jj]:
                    visited[ii][jj] =  visited[i][j] + 1
                    queue.append([ii,jj])
                elif space[ii][jj] == 0:
                    visited[ii][jj] =  visited[i][j] + 1
                    queue.append([ii,jj])
                    
	# 6. 후보 리스트는 우선 순위가 있기 때문에 정렬을 사용할 수 있다.
    return sorted(cand, key = lambda x: (x[0], x[1], x[2]))


i, j = pos
size = [2, 0]
# 8. 맨 앞의 후보만 먹고 위치 이동후 다시 BFS 해야한다
while True:
    space[i][j] = size[0]
    cand = deque(bfs(i,j))
    
    if not cand:
        break
        
    # 7. 후보리스트가 나오면 맨 앞의 후보 먹이를 뽑아 그 위치로 이동한다.
    step, xx, yy = cand.popleft()
    cnt += step
    size[1] += 1
    
	# 9. 몇 개를 먹었는지 몇 초간 이동했는지 체크해 줄 필요가 있다.
    if size[0] == size[1]:
        size[0] += 1
        size[1] = 0

    space[i][j] = 0
    i, j = xx, yy
        
print(cnt)