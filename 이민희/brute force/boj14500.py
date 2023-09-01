import sys

input = sys.stdin.readline

n, m = list(map(int, input().split()))
arr = []
for i in range(n) :
    arr.append(list(map(int, input().split())))

maxValue = 0

# ---- 모양 구현하기
for row_idx in range(n) :
    for col_idx in range(m) :
        if col_idx + 3 < m :
            maxValue = max(maxValue, sum(arr[row_idx][col_idx : col_idx + 4]))
        else :
            break
# | 모양 구현하기
for col_idx in range(m) :
    for row_idx in range(n) :
        if row_idx + 3 < n :
            tmp = arr[row_idx][col_idx] + arr[row_idx + 1][col_idx] + arr[row_idx + 2][col_idx] + arr[row_idx + 3][col_idx]
            maxValue = max(maxValue, tmp)
        else :
            break
# ㅁ 모양 구현하기
for row_idx in range(n) :
    for col_idx in range(m) :
        if row_idx + 1 < n and col_idx + 1 < m :
            tmp = arr[row_idx][col_idx] + arr[row_idx + 1][col_idx] + arr[row_idx][col_idx + 1] + arr[row_idx + 1][col_idx + 1]
            maxValue = max(maxValue, tmp)
        else :
            break

# (3, 2) 모양들 구현하기
for row_idx in range(n) :
    for col_idx in range(m) :
        if row_idx + 2 < n and col_idx + 1 < m :
            sum_list = []
            sum_tmp = arr[row_idx][col_idx] + arr[row_idx + 1][col_idx] + arr[row_idx][col_idx + 1] + arr[row_idx + 1][col_idx + 1] + arr[row_idx + 2][col_idx] + arr[row_idx + 2][col_idx + 1]
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx + 1] - arr[row_idx + 2][col_idx + 1])
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx] - arr[row_idx + 2][col_idx])
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx + 1] - arr[row_idx][col_idx + 1])
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx] - arr[row_idx][col_idx])
            sum_list.append(sum_tmp - arr[row_idx][col_idx + 1] - arr[row_idx + 2][col_idx])
            sum_list.append(sum_tmp - arr[row_idx][col_idx] - arr[row_idx + 2][col_idx + 1])
            sum_list.append(sum_tmp - arr[row_idx][col_idx + 1] - arr[row_idx + 2][col_idx + 1])
            sum_list.append(sum_tmp - arr[row_idx][col_idx] - arr[row_idx + 2][col_idx])
            maxValue = max(max(sum_list), maxValue)
        else :
            break

# (2, 3) 모양들 구현하기
for row_idx in range(n) :
    for col_idx in range(m) :
        if row_idx + 1 < n and col_idx + 2 < m :
            sum_list = []
            sum_tmp = sum(arr[row_idx][col_idx : col_idx + 3]) + sum(arr[row_idx + 1][col_idx : col_idx + 3])
            sum_list.append(sum_tmp - arr[row_idx][col_idx] - arr[row_idx + 1][col_idx + 2])
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx] - arr[row_idx][col_idx + 2])
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx] - arr[row_idx + 1][col_idx + 2])
            sum_list.append(sum_tmp - arr[row_idx][col_idx] - arr[row_idx][col_idx + 2])
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx + 1] - arr[row_idx + 1][col_idx + 2])
            sum_list.append(sum_tmp - arr[row_idx][col_idx + 1] - arr[row_idx][col_idx + 2])
            sum_list.append(sum_tmp - arr[row_idx + 1][col_idx] - arr[row_idx + 1][col_idx + 1])
            sum_list.append(sum_tmp - arr[row_idx][col_idx + 1] - arr[row_idx][col_idx])
            maxValue = max(max(sum_list), maxValue)
        else :
            break

print(maxValue)