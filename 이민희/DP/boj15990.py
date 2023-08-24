import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n) : arr.append(int(input()))

endnum = max(arr)
dp = [[0 for _ in range(3)] for _ in range(100001)]
dp[0] = [0, 0, 0]
dp[1] = [1, 0, 0]
dp[2] = [0, 1, 0]
dp[3] = [1, 1, 1]


for i in range(4, endnum + 1) :
    dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000009
    dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % 1000000009
    dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % 1000000009

for i in arr :
    print(sum(dp[i]) % 1000000009)