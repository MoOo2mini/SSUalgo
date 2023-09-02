# 3
# 8
# 0 0
# 7 0
# 100
# 0 0
# 30 50
# 10
# 1 1
# 1 1
from collections import deque
import sys
input = sys.stdin.readline

t = int(input())

r_list = [2, 2, -2, -2, 1, 1, -1, -1]
c_list = [1, -1, 1, -1, 2, -2, 2, -2]

result = []

for ____ in range(t) :
    L = int(input())
    cr, cc = list(map(int, input().split()))
    dr, dc = list(map(int, input().split()))

    if cr == dr and cc == dc :
        result.append(0)
        continue
    arr = [[0] * L for _ in range(L)]
    arr[cr][cc] = 1

    dq = deque()
    dq.append([cr, cc])
    
    while dq :
        fir = dq.popleft()

        for i in range(8) :
            rr = fir[0] + r_list[i]
            cc = fir[1] + c_list[i]
            if 0 <= rr < L and 0 <= cc < L :
                if arr[rr][cc] == 0 :
                    if rr == dr and cc == dc :
                        result.append(arr[fir[0]][fir[1]])
                        dq.clear()
                        break
                    else :
                        arr[rr][cc] = arr[fir[0]][fir[1]] + 1
                        dq.append([rr, cc])

print(*result, sep='\n')