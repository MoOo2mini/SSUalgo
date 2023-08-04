from copy import copy

n, m, r = map(int, input().split())
arr = list(list(map(int, input().split())) for _ in range(n))
result = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n) :
        for j in range(m) :
            result[i][j] = arr[i][j]
count = 0

div = ((n - 1) * 2 + (m - 1) * 2)
r %= div

while (r != 0) :
    while (min(n, m) / 2 != count) :
        for i in range(count, n - (count + 1), 1) :
            result[i + 1][count] = arr[i][count]

        for i in range(count, m - (count + 1), 1) :
            result[n - (count + 1)][i + 1] = arr[n - (count + 1)][i]

        for i in range(n - (count + 1), count, -1) :
            result[i - 1][m - (count + 1)] = arr[i][m - (count + 1)]

        for i in range(m - (count + 1), count, -1) :
            result[count][i - 1] = arr[count][i]
        
        count += 1
    for i in range(n) :
        for j in range(m) :
            arr[i][j] = result[i][j]
    r -= 1
    count = 0

for i in result :
    print(*i)