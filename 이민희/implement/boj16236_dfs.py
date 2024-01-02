n = int(input())

arr = []
y = 0
x = 0
for i in range(n) :
    tmp = list(map(int, input().split()))
    arr.append(tmp)
    index = -1
    try :
        index = tmp.index(9)
    except :
        continue
    y = i
    x = index
arr[y][x] = 0

def findEatableFish() :
    global sharkSize, arr
    for row in arr :
        for ss in range(1, sharkSize) :
            index = -1
            try :
                index = row.index(ss)
            except :
                continue
            if (index != -1) :
                return True
    return False
def getMovWay(second) :
    mov_way = set()
    for i in range(second + 1) :
        mov_way.add(tuple([i, second - i]))
        mov_way.add(tuple([i, (second - i) * -1]))
        mov_way.add(tuple([i * -1, (second - i) * -1]))
        mov_way.add(tuple([i * -1, second - i]))
    mov_way = sorted(mov_way, key=lambda x : (x[0], x[1]))
    return mov_way

direction = getMovWay(1)
visited = [[0] * n for _ in range(n)]
minCnt = [y, x, n ** 2]

def dfs(y, x, cnt) :
    global visited, minCnt, sharkSize
    if (cnt > n ** 2) :
        return
    if (0 < arr[y][x] < sharkSize) :
        if (minCnt[2] == cnt) :
            if (minCnt[0] > y) :
                minCnt[0] = y
                minCnt[1] = x
                minCnt[2] = cnt
            elif (minCnt[0] == y) :
                if (minCnt[1] > x) :
                    minCnt[0] = y
                    minCnt[1] = x
                    minCnt[2] = cnt
        elif (minCnt[2] > cnt) :
            minCnt[0] = y
            minCnt[1] = x
            minCnt[2] = cnt
        return
    for dd in direction :
        yy = y + dd[0]
        xx = x + dd[1]
        if not (0 <= yy < n and 0 <= xx < n) :
            continue
        if (visited[yy][xx] == 0) :
            # 미래의 장소가 크기가 같은 물고기가 있는 곳 또는 0이라면 이동.
            if (arr[yy][xx] == sharkSize or arr[yy][xx] == 0) :
                visited[yy][xx] = 1
                dfs(yy, xx, cnt + 1)
                visited[yy][xx] = 0
            elif (arr[yy][xx] < sharkSize) :
                visited[yy][xx] = 1
                dfs(yy, xx, cnt + 1)
                visited[yy][xx] = 0


movSecond = 0
second = 0
sharkSize = 2
eatenFish = 0

while (True) :
    tmpy, tmpx = minCnt[0], minCnt[1]
    arr[minCnt[0]][minCnt[1]] = 0
    visited[minCnt[0]][minCnt[1]] = 1
    dfs(minCnt[0], minCnt[1], 0)
    visited[tmpy][tmpx] = 0
    if not (findEatableFish()) :
        break
    if (tmpy == minCnt[0] and tmpx == minCnt[1]) :
        break
    if (0 < arr[minCnt[0]][minCnt[1]] < sharkSize) :
        movSecond += minCnt[2]
        eatenFish += 1
        if (sharkSize == eatenFish) :
            eatenFish = 0
            sharkSize += 1
    print(minCnt)
    minCnt[2] = n ** 2
print(movSecond)
