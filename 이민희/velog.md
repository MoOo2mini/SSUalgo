### 13460. 구슬 탈출 2
> 참고 여부 : X
소요 시간 : 1시간 30분

B자리에 R이 위치하게 될 때 B가 소실되는 문제점이 있었다. 이러한 TC를 찾느라 시간을 너무 많이 소비하였다.

다른 사람이 올려놓은 테케로 발견할 수 있었는데, 스스로 발견하지 못한 점이 아쉽다..

정답 코드
```python
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

```

### 2048(easy)

> 참고 여부 : X
소요 시간 : 1시간 30분

up 방향의 함수를 하나 짜고 배열을 회전해서 인풋으로 넣어주려 하였다.
그런데 4개의 함수를 다 짜고 나서야 실수를 했다는 것을 깨달았다..
```
2 0 2
0 0 0
2 0 2
```
위의 배열에서 up 방향으로 움직이면
```
4 0 4
0 0 0
0 0 0
```

이러한 모양이 되어야하는데, 인접한 수만 고려하도록 짰다. 그래서 갈아엎었다.

이 문제에서 가장 헷갈리고 어려웠던건 배열을 원하는 방향으로 뒤집는 것이었다.
"zip(*arr)"을 통해서 transpose를 할 수 있다. Numpy를 쓰기엔 너무 낭비같다.

arr = list(map(list,zip(*arr)))
이렇게 하면 쉽게 전치 행렬을 얻을 수 있다.


* 확실히 numpy가 좋긴하다.. 내장 함수도 많고 직관적이다. 코테에서 쓸 수 있는지는 찾아봐야겠다.

### 뱀

> 참고 여부 : X
소요 시간 : 1시간 40분

뱀의 꼬리를 컨트롤하는게 생각보다 어려웠다..

```
5
2
2 5
2 4
6
4 D
5 D
6 D
7 D
8 D
9 D
```
해당 반례를 통해 내가 어디서 실수했는지 알 수 있었다.
뱀의 몸통을 1만으로 구성하고, 상하좌우를 탐색해 1이 있으면 그곳을 꼬리로 잡았는데

```
1 0
1 1
```

뱀이 이러한 꼴을 하고 있을 때 꼬리를 제대로 잡지 못하였다.
이를 보완하기 위해 뱀의 몸통을 current_time + 1로 하였다.

맨날 히든 테케에서 걸리는데.. 나 취업 가능?

```
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
```