n = int(input())

dp = [0 for _ in range(n + 100)]
dp[1] = 0
dp[2] = 1
dp[3] = 1

if (n < 4) :
    print(dp[n])
else :
    for i in range(4, n + 1, 1) :
        num = dp[i - 1] + 1
        if (i % 3 == 0) :
            num = min(dp[i // 3] + 1, num)
        if (i % 2 == 0) :
            num = min(dp[i // 2] + 1, num)
        dp[i] = num

    print(dp[n])