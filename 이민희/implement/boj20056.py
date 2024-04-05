n, m, k = map(int, input().split())

from copy import deepcopy as dc

fireball_index = [x for x in range(1, m + 1)]
fireball_info = {}

arr = [[[0] for _ in range(n)] for _ in range(n)]
for i in range(1, m + 1) :
    r, c, m, s, d = map(int, input().split())
    fireball_info[i] = [r, c, m, s, d]
    arr[r - 1][c - 1] = [i]

tmparr = [[[0] for _ in range(n)] for _ in range(n)]
col_yx = [] # 충돌나는 위치 저장

dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

for _ in range(k) :
    tmparr = [[[0] for _ in range(n)] for _ in range(n)]
    col_yx = [] # 충돌나는 위치 저장
    for i in fireball_index :
        r, c, m, s, d = fireball_info[i]

        y = r
        x = c
        yy = (dy[d] * s) + y
        xx = (dx[d] * s) + x

        if yy < 1 :
            yy = ((yy % n) * -1) + n
        elif yy > n: 
            yy = (yy % n)
            if yy == 0 :
                yy = n
        if xx < 1 :
            xx = ((xx % n) * -1) + n
        elif xx > n: 
            xx = (xx % n)
            if xx == 0 :
                xx = n
        if (tmparr[yy - 1][xx - 1][0] != 0) :
            # 충돌 발생
            # 충돌 지점에 넣어주기
            col_yx.append([yy - 1, xx - 1])
            # tmparr에 표시하기
            tmparr[yy - 1][xx - 1].append(i)        
        else :
            tmparr[yy - 1][xx - 1][0] = i
            fireball_info[i] = [yy, xx, m, s, d]

    # 충돌난 부분 처리하기
    for col in col_yx :
        y, x = col
        idxes = tmparr[y][x]

        nm = 0
        ns = 0
        nd = 0
        for i in idxes :
            _, _, m, s, d = fireball_info[i]
            nm += m
            ns += s
            nd += d
            fireball_index.remove(i)
            fireball_info.pop(i)
        nm = nm // 5
        if nm == 0: 
            tmparr[y][x] = [0]
            continue
        ns = (ns // len(idxes))
        if (nd % 2 == 0) :
            nd = [0, 2, 4, 6]
        else :
            nd = [1, 3, 5, 7]
        
        # 현재 있는 부분은 다시 0으로 채워주기
        tmparr[y][x] = [0]

        for dd in nd :            
            if len(fireball_index) == 0 :
                new_shark_idx = 1
            else :
                new_shark_idx = fireball_index[-1] + 1
            if len(tmparr[yy - 1][xx - 1]) == 1 :
                tmparr[yy - 1][xx - 1][0] = new_shark_idx
                fireball_index.append(new_shark_idx)
            fireball_info[new_shark_idx] = [y + 1, x + 1, nm, ns, dd]
    # 9시 58분 - 1시 47분 (휴식)

    answer = 0        
    for idx in fireball_index :
        _, _, m, _, _ = fireball_info[idx] 
        answer += m
    arr = dc(tmparr)
print(answer)