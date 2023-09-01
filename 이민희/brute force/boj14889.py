import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n) :
    arr.append(list(map(int, input().split())))

visited = [0] * n
start = []
minValue = (20 ** 2) * 1000

def sum_arr(team) :
    result_sum = 0
    for i in team :
        for j in team :
            result_sum += arr[i][j]
    return result_sum

def combination(idx) :
    global minValue
    if len(start) == n // 2 :
        link = []
        for i in range(n) :
            if not i in start :
                link.append(i)
        minValue = min(minValue, abs(sum_arr(start) - sum_arr(link)))
    else :
        for i in range(idx, n) :
            if visited[i] == 0 :
                visited[i] = 1
                start.append(i)
                combination(i + 1)
                visited[i] = 0
                start.pop()

combination(0)
print(minValue)