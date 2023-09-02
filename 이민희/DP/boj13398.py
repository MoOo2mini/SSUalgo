import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
reversed_arr = arr[::-1]

L2R_dp = [[] for _ in range(n)]
R2L_dp = [[] for _ in range(n)]

L2R_dp[0] = arr[0]
R2L_dp[0] = reversed_arr[0]
for i in range(1, n) :
    L2R_dp[i] = max(arr[i], L2R_dp[i - 1] + arr[i])
    R2L_dp[i] = max(reversed_arr[i], R2L_dp[i - 1] + reversed_arr[i])

R2L_dp = R2L_dp[::-1]

unjump = max(L2R_dp)
maxValue = L2R_dp[0]
for i in range(1, n - 1) :
    maxValue = max(maxValue, R2L_dp[i + 1] + L2R_dp[i - 1])

print(max(unjump, maxValue))