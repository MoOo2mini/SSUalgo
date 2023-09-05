from collections import deque
import sys

input = sys.stdin.readline
goal_num = int(input())

current_num = 1
clipboard_num = 0
time = 0

dq = deque()
dq.append([current_num, clipboard_num, time])
visited = [[0] * 1001 for _ in range(1001)]
visited[1][0] = 1

while dq :
    fir = dq.popleft()
    current_num = fir[0]
    clipboard_num = fir[1]
    time = fir[2]

    if current_num == goal_num :
        print(time)
        exit()
    if 1000 >= current_num >= 0 and visited[current_num][current_num] == 0:
        dq.append([current_num, current_num, time + 1])
        visited[current_num][current_num] = 1
    if 1000 >= current_num + clipboard_num >= 0 and visited[current_num + clipboard_num][clipboard_num] == 0 :
        if current_num + clipboard_num == goal_num :
            print(time + 1)
            exit()
        else:
            dq.append([current_num + clipboard_num, clipboard_num, time + 1])
            visited[current_num + clipboard_num][clipboard_num] = 1
    if 1000 >= current_num - 1 > 0 and visited[current_num - 1][clipboard_num] == 0 :
        if current_num - 1 == goal_num :
            print(time + 1)
            exit()
        dq.append([current_num - 1, clipboard_num, time + 1])
        visited[current_num - 1][clipboard_num] = 1