from collections import deque
import sys

input = sys.stdin.readline
n, k = list(map(int, input().split()))

oper3 = lambda x, y : [x + 1, y + 1]
oper2 = lambda x, y : [x - 1, y + 1]
oper1 = lambda x, y : [x * 2, y]

dq = deque()
dq.append([n, 0])

visited = [0] * 100001
visited[n] = 0

while dq :
    current, time = dq.popleft()
    if current == k :
        print(time)
        exit()
    for oper in [oper1, oper2, oper3] :
        n_current, n_time = oper(current, time)
        if 0 <= n_current <= 100000 and visited[n_current] == 0 :
            visited[n_current] = 1
            dq.append([n_current, n_time])