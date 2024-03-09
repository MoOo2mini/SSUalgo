t = int(input())
answer = []
for _ in range(t) :
    n = int(input())
    dp = [0] * 100
    dp[0] = 1
    dp[1] = 1
    dp[2] = 1
    dp[3] = 2
    dp[4] = 2
    dp[5] = 3
    dp[6] = 4
    dp[7] = 5
    dp[8] = 7

    if (n < 9) :
        answer.append(dp[n - 1])
        continue
    for i in range(9, n) :
        dp[i] = dp[i - 1] + dp[i - 5]
    answer.append(dp[n - 1])

print(*answer, sep='\n')