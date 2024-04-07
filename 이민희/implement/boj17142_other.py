import sys
from collections import deque

# [[0, 0], [0, 2], [1, 5], [2, 3], [3, 0]]

# BFS로 바이러스 퍼트리는 함수
def bfs(viruses):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    que = deque()
    isVisited = [[-1 for _ in range(N)] for _ in range(N)]

    for virus in viruses:
        que.append([virus[0], virus[1]])
        isVisited[virus[0]][virus[1]] = 0

    total_time = 0
    while que:
        now = que.popleft()

        nowX = now[0]
        nowY = now[1]
        nowTime = isVisited[nowX][nowY]

        for t in range(4):
            nx = nowX + dx[t]
            ny = nowY + dy[t]
            # 범위 체크
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
			# 빈 자리 and 아직 방문 안한 자리
            if board[nx][ny] == 0 and isVisited[nx][ny] == -1:
                que.append([nx, ny])
                isVisited[nx][ny] = nowTime + 1
                # 여기만 걸린 시간 갱신
                total_time = max(total_time, nowTime + 1)
            # 비활성 바이러스 자리 and 아직 방문 안한 자리
            elif board[nx][ny] == 2 and isVisited[nx][ny] == -1:
                que.append([nx, ny])
                isVisited[nx][ny] = nowTime + 1

    # 벽 제외하고 바이러스가 퍼지지 못한 구역이 있는지 확인
    w_cnt = 0
    for i in range(N):
        for j in range(N):
            if isVisited[i][j] == -1:
                w_cnt += 1

    if w_cnt != wall_cnt:
        return 1e9

    return total_time

# 활성화시킬 바이러스 위치를 조합으로 구하는 함수
def find_case(depth, start):
    global min_
    # 조합 완성
    if depth == M:
        # 바이러스 놓을 위치를 M개 고르면 BFS로 퍼트리기
        min_ = min(min_, bfs(viruses))

        return

    for i in range(start, len(virus_pos)):
        viruses.append(virus_pos[i])

        find_case(depth + 1, i + 1)

        viruses.pop()


N, M = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]


wall_cnt = 0
# 바이러스 위치를 배열에 저장
virus_pos = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 2:
            virus_pos.append([i, j])
        elif board[i][j] == 1:
            wall_cnt += 1

min_ = 1e9
# 바이러스 3개 고르는 경우
viruses = []

# find_case(0, 0)
bfs([[0, 0], [0, 2], [1, 5], [2, 3], [3, 0]])

if min_ != 1e9:
    print(min_)
else:
    print(-1)