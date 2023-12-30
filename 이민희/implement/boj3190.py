# 사과 = -1

timer = 0
direction = [[-1, 0], [0, 1], [1, 0], [0, -1]]
current_dir = 1

N = int(input())
arr = [[0] * N for _ in range(N)]
arr[0][0] = 1

k = int(input())
for _ in range(k) :
    y, x = map(int, input().split())
    arr[y - 1][x - 1] = -1

l = int(input())
change_time = []
for _ in range(l) :
    x, c = input().split()
    x = int(x)
    change_time.append([x, c])

snake_head = [0, 0]
snake_tail = [0, 0]
current_time = -1
x, c = change_time.pop(0)

while (True) :
    current_time += 1
    # 시간 체크하면서 방향 바꾸기
    if (x == current_time) :
        if (c == 'D') :
            current_dir = (current_dir + 1) % 4
        if (c == 'L') :
            current_dir = (current_dir - 1) % 4
        if (len(change_time) > 0) :
            x, c = change_time.pop(0)

    # 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
    if not ((0 <= snake_head[0] + direction[current_dir][0] < N) and (0 <= snake_head[1] + direction[current_dir][1] < N)) :
        break
    elif (arr[snake_head[0] + direction[current_dir][0]][snake_head[1] + direction[current_dir][1]] != 0
          and arr[snake_head[0] + direction[current_dir][0]][snake_head[1] + direction[current_dir][1]] != -1):
        break
    
    apple = False
    if (arr[snake_head[0] + direction[current_dir][0]][snake_head[1] + direction[current_dir][1]] == -1) :
        apple = True
    # 뱀의 머리를 방향대로 늘림.
    arr[snake_head[0] + direction[current_dir][0]][snake_head[1] + direction[current_dir][1]] = (current_time + 1)
    snake_head = [snake_head[0] + direction[current_dir][0], snake_head[1] + direction[current_dir][1]]
    
    # 사과를 먹지 않았다면 꼬리 줄이기.
    if not apple :
        arr[snake_tail[0]][snake_tail[1]] = 0
        minValue = 999999
        tail_4 = [999999] * 4

        idx = 0
        for dd in direction :
            if (0 <= snake_tail[0] + dd[0] < N and 0 <= snake_tail[1] + dd[1] < N) :
                if ((arr[snake_tail[0] + dd[0]][snake_tail[1] + dd[1]] != 0) or (arr[snake_tail[0] + dd[0]][snake_tail[1] + dd[1]] != -1)) :
                    if (arr[snake_tail[0] + dd[0]][snake_tail[1] + dd[1]] == 0 or arr[snake_tail[0] + dd[0]][snake_tail[1] + dd[1]] == -1) :
                        idx += 1
                        continue
                    else :
                        tail_4[idx] = arr[snake_tail[0] + dd[0]][snake_tail[1] + dd[1]]
                        idx += 1
            else :
                idx += 1
        idx = tail_4.index(min(tail_4))
        snake_tail = [snake_tail[0] + direction[idx][0], snake_tail[1] + direction[idx][1]]
        
print(current_time + 1)