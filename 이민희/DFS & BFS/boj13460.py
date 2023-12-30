n, m = map(int, input().split())
origin_arr = []

R = [0, 0]
B = [0, 0]
hole = [0, 0]
for _ in range(n) :
    tmp = input()
    # origin_arr.append(list(input()))
    index_r = tmp.find('R')
    if (index_r != -1) :
        R = [_, index_r]
    index_b = tmp.find('B')
    if (index_b != -1) :
        B = [_, index_b]
    index_hole = tmp.find('O')
    if (index_hole != -1) :
        hole = [_, index_hole]
    origin_arr.append(list(tmp))

visited = set() # visited에 넣을땐 tuple로 넣기!
q = []
direction = [[-1, 0], [1, 0], [0, -1], [0, 1]] # 상하좌우
result = 9999999

current_r = R
current_b = B
q.append([R, B, 0])
visited.add(tuple([*R, *B]))
before_r = [0, 0]
before_b = [0, 0]

while (q) :
    before_r = [current_r[0], current_r[1]]
    before_b = [current_b[0], current_b[1]]

    current_r, current_b, cnt = q.pop(0)
    origin_arr[before_r[0]][before_r[1]] ='.'
    origin_arr[current_r[0]][current_r[1]] = 'R'
    if (origin_arr[before_b[0]][before_b[1]] != 'R') : 
        origin_arr[before_b[0]][before_b[1]] ='.'
    origin_arr[current_b[0]][current_b[1]] = 'B'
    
    cnt += 1
    if (cnt > 10) :
        continue
    for dd in direction :
        flag_r = False
        flag_b = False
        frontB = False

        # 움직이고자 하는 방향에서 B가 먼저인지 파악
        tmpy = current_r[0]
        tmpx = current_r[1]
        while (0 < tmpy + dd[0] < n - 1 and 0 < tmpx + dd[1] < m - 1) :
            if (origin_arr[tmpy + dd[0]][tmpx + dd[1]] == '.') :
                tmpy += dd[0]
                tmpx += dd[1]
            if (origin_arr[tmpy + dd[0]][tmpx + dd[1]] == 'B') :
                frontB = True
                break
            if (origin_arr[tmpy + dd[0]][tmpx + dd[1]] == '#') :
                break
            if (origin_arr[tmpy + dd[0]][tmpx + dd[1]] == 'O') :
                break
        if not (frontB) :
            yy, xx = current_r

            while (0 < yy + dd[0] < n - 1 and 0 < xx + dd[1] < m - 1) :
                if ((origin_arr[yy + dd[0]][xx + dd[1]] == '.') or (origin_arr[yy + dd[0]][xx + dd[1]] == 'O')) :
                    yy += dd[0]
                    xx += dd[1]
                    if (origin_arr[yy][xx] == 'O') :
                        flag_r = True
                        break
                else :
                    break
            origin_arr[current_r[0]][current_r[1]] = '.'
            if not flag_r:
                origin_arr[yy][xx] = 'R'
            y, x = current_b
            while ((0 < y + dd[0] < n - 1 and 0 < x + dd[1] < m - 1) and 
                    (origin_arr[y + dd[0]][x + dd[1]] == '.' or origin_arr[y + dd[0]][x + dd[1]] == 'O')) :
                y += dd[0]
                x += dd[1]
                if (origin_arr[y][x] == 'O') :
                    flag_b = True
                    break
            origin_arr[current_b[0]][current_b[1]] = '.'
            if not flag_b :
                origin_arr[y][x] = 'B'
        
        else :
            y, x = current_b
            while ((0 < y + dd[0] < n - 1 and 0 < x + dd[1] < m - 1) and 
                    (origin_arr[y + dd[0]][x + dd[1]] == '.' or origin_arr[y + dd[0]][x + dd[1]] == 'O')) :
                y += dd[0]
                x += dd[1]
                if (origin_arr[y][x] == 'O') :
                    flag_b = True
                    break
            origin_arr[current_b[0]][current_b[1]] = '.'
            if not flag_b :
                origin_arr[y][x] = 'B'
            yy, xx = current_r
            while (0 < yy + dd[0] < n - 1 and 0 < xx + dd[1] < m - 1) :
                if ((origin_arr[yy + dd[0]][xx + dd[1]] == '.') or (origin_arr[yy + dd[0]][xx + dd[1]] == 'O')) :
                    yy += dd[0]
                    xx += dd[1]
                    if (origin_arr[yy][xx] == 'O') :
                        flag_r = True
                        break
                else :
                    break
            origin_arr[current_r[0]][current_r[1]] = '.'
            if not flag_r:
                origin_arr[yy][xx] = 'R'

        if (flag_r and not flag_b) :
            result = min(result, cnt)
        elif not (flag_b) :
            if not tuple([yy, xx, y, x]) in visited :
                visited.add(tuple([yy, xx, y, x]))
                q.append([[yy, xx], [y, x], cnt])
        
        if (origin_arr[yy][xx] == 'R') :
            origin_arr[yy][xx] = '.'
            origin_arr[current_r[0]][current_r[1]] = 'R'
        elif (origin_arr[yy][xx] == 'O') :
            origin_arr[current_r[0]][current_r[1]] = 'R'

        if (origin_arr[y][x] == 'B') :
            origin_arr[y][x] = '.'
            origin_arr[current_b[0]][current_b[1]] = 'B'
        elif (origin_arr[y][x] == 'R') :
            origin_arr[current_b[0]][current_b[1]] = 'B'
        elif (origin_arr[y][x] == 'O') :
            origin_arr[current_b[0]][current_b[1]] = 'B'

if result == 9999999 :
    print(-1) 
else :
    print(result)
