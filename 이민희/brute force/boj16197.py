import sys
sys.setrecursionlimit(10**6)

n, m = list(map(int, input().split()))
coin_xy = []
wall_xy = []
visited_xy = []
for i in range(n) :
    tmp = list(input())
    for j in range(len(tmp)) : 
        t = tmp[j]
        if (t == 'o') :
            coin_xy.append([i, j])
        if (t == '#') :
            wall_xy.append([i, j])
    tmp.clear()
visited_xy.append(coin_xy)
visited_xy.sort()

xx = [-1, 1, 0, 0]
yy = [0, 0, -1, 1]

minValue = 999999999

def move(coins, cnt) :
    if cnt >= 10 :
        return
    global coin_xy, visited_xy, wall_xy, minValue

    for i in range(4) :
        fall_coin_cnt = 0
        tmp_visited = []
        for coin in coins :
            new_x = coin[1] + xx[i]
            new_y = coin[0] + yy[i]
            if ((new_x >= 0 and new_x < m) and (new_y >= 0 and new_y < n)) :
                if ([new_y, new_x] not in wall_xy) :
                    if ([new_y, new_x] not in tmp_visited) :
                        tmp_visited.append([new_y, new_x])
                else :
                    if (coin not in tmp_visited) :
                        tmp_visited.append(coin)
            else :
                fall_coin_cnt += 1
        tmp_visited.sort()
        if ((len(tmp_visited) + fall_coin_cnt) == len(coin_xy)) :
            if (fall_coin_cnt == 1) :
                minValue = min(cnt, minValue)
                return
            if (fall_coin_cnt == 0) :
                if (tmp_visited not in visited_xy) :
                    visited_xy.append(tmp_visited)
                    move(tmp_visited, cnt + 1)
move(coin_xy, 1)
if not minValue == 999999999 :
    print(minValue)
else :
    print(-1)

# 6 2
# ..
# ..
# o.
# o#
# .#
# ##