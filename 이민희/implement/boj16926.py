import sys
import math
def lcm(a, b):
    return a * b // math.gcd(a, b)

input = sys.stdin.readline

n, m, r = map(int, input().split())
arr = list(list(map(int, input().split())) for _ in range(n))

count = 0

# print(lcm(10, 6))
mod = ((n - 1) * 2 + (m - 1) * 2)
div = mod
for i in range(0, min(n, m), 2) :
    div = (n - i - 1) * 2 + (m - i - 1) * 2
    mod = lcm(mod, div)

r %= mod
maxcount = min(n, m) // 2
for _ in range(r) :
    for count in range(maxcount) :
    # while (min(n, m) // 2 != count) :
        prev = arr[count][count]
        tmp = arr[count][count]
        for i in range(count, n - (count + 1), 1) :
            tmp = arr[i + 1][count]
            arr[i + 1][count] = prev
            prev = tmp

        for i in range(count, m - (count + 1), 1) :
            tmp = arr[n - (count + 1)][i + 1]
            arr[n - (count + 1)][i + 1] = prev
            prev = tmp

        for i in range(n - (count + 1), count, -1) :
            tmp = arr[i - 1][m - (count + 1)]
            arr[i - 1][m - (count + 1)] = prev
            prev = tmp

        for i in range(m - (count + 1), count, -1) :
            tmp = arr[count][i - 1]
            arr[count][i - 1] = prev
            prev = tmp
        

for i in arr :
    print(*i)