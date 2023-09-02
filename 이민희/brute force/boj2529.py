import sys, copy
input = sys.stdin.readline

k = int(input())
arr = list(input().split())

result = []
visited = [0] * 10

maxValue = 0
minValue = 99999999999
maxList = []
minList = []
def permutation(current_num, arr_idx, result_num) :
    global maxValue, minValue, minList, maxList
    if len(result) == k + 1 :
        if maxValue < result_num :
            maxList = copy.deepcopy(result)
            maxValue = result_num
        if minValue > result_num :
            minList = copy.deepcopy(result)
            minValue = result_num
    else :
        if arr[arr_idx] == '<' :
            for i in range(current_num + 1, 10) :
                if visited[i] == 0 :
                    visited[i] = 1
                    result.append(i)
                    permutation(i, arr_idx + 1, result_num * 10 + i)
                    visited[i] = 0
                    result.pop()
        elif arr[arr_idx] == '>' :
            for i in range(current_num - 1, 0 - 1, -1) :
                if visited[i] == 0 :
                    visited[i] = 1
                    result.append(i)
                    permutation(i, arr_idx + 1, result_num * 10 + i)
                    visited[i] = 0
                    result.pop()

for num in range(10) :
    result.append(num)
    visited[num] = 1
    permutation(num, 0, num)
    visited[num] = 0
    result.pop()

print(*maxList, sep='')
print(*minList, sep='')