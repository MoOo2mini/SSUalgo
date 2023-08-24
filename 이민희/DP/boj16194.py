n = int(input())
arr = list(map(int, input().split()))

dp = [[0] * (n + 1), [0] * (n + 1)]
for i in range(n) :
    dp[0][i + 1] = arr[0] * (i + 1)

for i in range(1, len(arr)) :
    card = i + 1

    for j in range(1, n + 1) :
        if (card > j) :
            dp[1][j] = dp[0][j]
        else :
            dp[1][j] = min(dp[1][j - card] + arr[i], dp[0][j])
    for i in range(1, n + 1) :
        dp[0][i] = dp[1][i]
print(dp[0][n])