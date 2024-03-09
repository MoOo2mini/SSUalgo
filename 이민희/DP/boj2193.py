n = int(input())

dp0 = [0] * 91
dp1 = [0] * 91

dp1[0] = 1
dp0[0] = 0

for i in range(1, n) :
    dp1[i] = dp0[i - 1]
    dp0[i] = dp1[i - 1] + dp0[i - 1]

print(dp1[n - 1] + dp0[n - 1])