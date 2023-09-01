n = int(input())
arr = list(map(int, input().split()))
reversed_arr = arr[::-1]

increaseDp = [1 for _ in range(n)]
decreaseDp = [1 for _ in range(n)]

for i in range(1, n) :
    for j in range(i) :
        if arr[j] < arr[i] :
            increaseDp[i] = max(increaseDp[i], increaseDp[j] + 1)
        if reversed_arr[j] < reversed_arr[i] :
            decreaseDp[i] = max(decreaseDp[i], decreaseDp[j] + 1)

result = [0 for i in range(n)]
for i in range(n):
    result[i] = increaseDp[i] + decreaseDp[n - i - 1] - 1

print(max(result))