# LIS 문제

n = int(input())
arr = []

for _ in range(n) :
    a, b = map(int, input().split())
    arr.append((a, b))
arr.sort()
dp = [1] * n
for i in range(1, n) :
    for j in range(i) :
        _, back = arr[i]
        _, front = arr[j]

        if front < back :
            dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))