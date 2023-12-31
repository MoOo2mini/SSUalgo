n, m = map(int, input().split())
r, c, d = map(int, input().split())

arr = []
for _ in range(n) :
    arr.append(list(map(int, input().split())))

direction = [[-1, 0], [0, 1], [1, 0], [0, -1]]

current_y = r 
current_x = c
direction_idx = d

cnt = 0

while (True) :
    if (arr[current_y][current_x] == 0) :
        arr[current_y][current_x] = -1
        cnt += 1

    all_clean = True
    # 주변의 4칸 탐색
    for dd in range(1, 5, 1) :
        yy, xx = direction[(direction_idx - dd) % 4]
        if not (0 <= current_x + xx < m and 0 <= current_y + yy < n) :
            continue
        if (arr[current_y + yy][current_x + xx] == 0) :
            direction_idx = (direction_idx - dd) % 4
            current_y += yy
            current_x += xx
            all_clean = False
            break
    if all_clean :
        yy, xx = direction[(direction_idx - 2) % 4]
        if not (0 <= current_x + xx < m and 0 <= current_y + yy < n) :
            continue
        if (arr[current_y + yy][current_x + xx] != 1) :
            current_y += yy
            current_x += xx
        elif (arr[current_y + yy][current_x + xx] == 1) :
            break
print(cnt)