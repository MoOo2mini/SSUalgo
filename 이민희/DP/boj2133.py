n = int(input())

dp = [0] * 31

dp[0] = 1
dp[2] = 3
dp[4] = 11

for i in range(6, 31, 2) :
    dp[i] += dp[i - 2] * dp[2]
    for j in range(0, i - 2, 2) :
        dp[i] += dp[j] * 2

print(dp[n])