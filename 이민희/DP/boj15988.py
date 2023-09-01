import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n) : arr.append(int(input()))

endnum = max(arr)
dp = [0] * (endnum + 1)
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(4, endnum + 1) :
    dp[i] = (dp[i - 1] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 3] % 1000000009) % 1000000009

for i in arr :
    print(dp[i])