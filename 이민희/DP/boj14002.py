n = int(input())
arr = list(map(int, input().split()))

dp = [[arr[i]] for i in range(n)]

for i in range(1, n) :
    for j in range(i) :
        if arr[j] < arr[i] and len(dp[j]) + 1 > len(dp[i]) and dp[j][-1] < arr[i] :
            dp[i] = dp[j].copy()
            dp[i].append(arr[i])

dp.sort(key=len)
dp[-1].sort()
print(len(dp[-1]))
print(*dp[-1])