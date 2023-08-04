dp = [1 for _ in range(10)]
arr = [1 for _ in range(10)]
n = int(input())

if (n == 1) : 
    print(sum(dp))
else :
    for i in range(1, n) :
        dp[0] = sum(dp)
        for j in range(1, 10, 1) :
            dp[j] = (dp[j - 1] - arr[j - 1]) % 10007
        for j in range(10) :
            arr[j] = dp[j]
    print(sum(dp) % 10007)