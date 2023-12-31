
dice = [0] * 6

def turn(direct, y, x) :
    global dice
    global arr
    a, b, c, d, e, f = dice
    if (direct == 1) :
        dice[0] = d
        dice[2] = a
        dice[3] = f
        dice[5] = c
    if (direct == 2) :
        dice[0] = c
        dice[2] = f
        dice[3] = a
        dice[5] = d
    if (direct == 3) :
        dice[0] = e
        dice[1] = a
        dice[4] = f
        dice[5] = b
    if (direct == 4) :
        dice[0] = b
        dice[1] = f
        dice[4] = a
        dice[5] = e
    
    if (arr[y][x] != 0) :
        dice[5] = arr[y][x]
        arr[y][x] = 0
    else :
        arr[y][x] = dice[5]


n, m, x, y, k = map(int, input().split())

arr = []
for _ in range(n) :
    arr.append(list(map(int, input().split())))
commend = list(map(int, input().split()))

current_x = y
current_y = x
direction = [[0, 1], [0, -1], [-1, 0], [1, 0]] # 동서북남 -> 오 왼 위 아래 
for i in range(k) :
    # 먼저 갈 수 있는 곳인지 판단. 아니라면 넘김
    yy = direction[commend[i] - 1][0]
    xx = direction[commend[i] - 1][1]
    if not (0 <= current_x + xx < m and 0 <= current_y + yy < n) :
        continue
    current_y += yy
    current_x += xx
    turn(commend[i], current_y, current_x)
    print(dice[0])
