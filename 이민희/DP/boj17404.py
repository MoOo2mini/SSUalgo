n = int(input())
tmp = []
for i in range(n) :
    tmp.append(list(map(int, input().split())))

import copy

ans = 1000 * 1000 + 1
for first_color in range(3) :
    dp = copy.deepcopy(tmp)
    dp[1][first_color - 2] += dp[0][first_color]
    dp[1][first_color - 1] += dp[0][first_color]
    if (n > 2) :
        dp[2][first_color] += min(dp[1][first_color - 1], dp[1][first_color - 2])
        dp[2][first_color - 2] += dp[1][first_color - 1]
        dp[2][first_color - 1] += dp[1][first_color - 2]

        for i in range(3, n) :
            dp[i][first_color] += min(dp[i - 1][first_color - 2], dp[i - 1][first_color - 1])
            dp[i][first_color - 2] += min(dp[i - 1][first_color], dp[i - 1][first_color - 1])
            dp[i][first_color - 1] += min(dp[i - 1][first_color], dp[i - 1][first_color - 2])

    ans = min([ans, dp[-1][first_color - 2], dp[-1][first_color - 1]])

print(ans)