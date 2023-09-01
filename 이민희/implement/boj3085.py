n = int(input())

def check_row(row) :
    max_row = 0
    dp = [1] * n
    for i in range(1, n) :
        if arr[row][i - 1] == arr[row][i] :
            dp[i] += dp[i - 1]
    max_row = max(max_row, max(dp))
    return max_row

def check_col(col) :
    max_col = 0
    dp = [1] * n
    for i in range(1, n) :
        if arr[i][col] == arr[i - 1][col] :
            dp[i] += dp[i - 1]
    max_col = max(max_col, max(dp))
    return max_col

arr = []
for i in range(n) :
    arr.append(list(input()))

maxValue = 0
for col in range(n) :
    for i in range(1, n) :
        if arr[i][col] != arr[i - 1][col] :
            #change
            tmp = arr[i][col]
            arr[i][col] = arr[i - 1][col]
            arr[i - 1][col] = tmp
            #check
            maxValue = max([maxValue, check_col(col), check_row(i), check_row(i - 1)])
            #change again
            tmp = arr[i][col]
            arr[i][col] = arr[i - 1][col]
            arr[i - 1][col] = tmp
        else :
            maxValue = max([maxValue, check_col(col), check_row(i), check_row(i - 1)])

for row in range(n) :
    for i in range(1, n) :
        if arr[row][i] != arr[row][i - 1] :
            #change
            tmp = arr[row][i]
            arr[row][i] = arr[row][i - 1]
            arr[row][i - 1] = tmp
            #check
            maxValue = max([maxValue, check_col(i), check_col(i - 1), check_row(row)])
            #change again
            tmp = arr[row][i]
            arr[row][i] = arr[row][i - 1]
            arr[row][i - 1] = tmp
        else :
            #check
            maxValue = max([maxValue, check_col(i), check_col(i - 1), check_row(row)])
print(maxValue)