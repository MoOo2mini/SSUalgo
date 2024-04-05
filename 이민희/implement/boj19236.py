arr = []

from copy import deepcopy as dc
directions = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]
# 상어가 있는 공간 -> arr[-1]
eatenFish = set()
maxV = 0
for _ in range(4) :
    a, b, c, d, e, f, g, h = map(int, input().split())
    arr.append([(a, b),(c, d), (e, f), (g, h)])

# (0, 0)에 상어 넣기
a, b = arr[0][0]
eatenFish.add(a)
arr[0][0] = (-1, b)
# print(arr)

# 원하는 물고기 찾기
def findFishXY(arr, fishNum) :
    if fishNum in eatenFish :
        return None
    for i in range(4) :
        for j in range(4) :
            num, _ = arr[i][j]
            if num == fishNum :
                return [i, j]

def movingFish(arr, eatenFish) :  
    global maxV         
    fishNum = 1
    while (fishNum <= 16) :
        fishXY = findFishXY(arr, fishNum)
        if (fishXY == None) :
            fishNum += 1
            continue
        number, direction = arr[fishXY[0]][fishXY[1]]

        # 갈 수 있는 공간인지 판단
        yy, xx = directions[direction - 1]

        if (0 <= fishXY[0] + yy < 4 and 0 <= fishXY[1] + xx < 4) :
            # 갈 수는 있는데 상어가 있어.
            num, dir = arr[fishXY[0] + yy][fishXY[1] + xx]
            if (num == -1) :
                # 돌아
                direction += 1
                if (direction == 9) :
                    direction = 1
                arr[fishXY[0]][fishXY[1]] = (number, direction)
            else :
                # swap
                tmpnum, tmpdir = number, direction
                arr[fishXY[0] + yy][fishXY[1] + xx] = (tmpnum, tmpdir)
                arr[fishXY[0]][fishXY[1]] = (num, dir)
                fishNum += 1
        else :
            # 돌아
            direction += 1
            if (direction == 9) :
                direction = 1
            arr[fishXY[0]][fishXY[1]] = (number, direction)

    # 상어 움직이기
    yy, xx = findFishXY(arr, -1)
    _, dir = arr[yy][xx]
    diry, dirx = directions[dir - 1]
    for i in range(1, 4) :
        y = yy + diry * i
        x = xx + dirx * i
        if not (0 <= y < 4 and 0 <= x < 4) :
            break
        num, dd = arr[y][x]

        if (1 <= num <= 16) :
            # 현재 상어의 자리 비우기
            tmp = dc(arr)
            arr[yy][xx] = (0, 0)
            arr[y][x] = (-1, dd)
            eatenFish.add(num)
            movingFish(arr, eatenFish)
            maxV = max(maxV, sum(eatenFish))
            eatenFish.remove(num)
            arr = tmp

movingFish(arr, eatenFish)
print(maxV)