import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n) :
    arr.append(list(map(int, input().split())))

visited = [0] * n
start = []
link = [x for x in range(n)]
minValue = (20 ** 2) * 1000

def sum_arr(team) :
    result_sum = 0
    for i in team :
        for j in team :
            result_sum += arr[i][j]
    return result_sum

def combination(idx, num) :
    global minValue
    if len(start) == num :
        # link = []
        # for i in range(n) :
        #     if not i in start :
        #         link.append(i)
        minValue = min(minValue, abs(sum_arr(start) - sum_arr(link)))
    else :
        for i in range(idx, n) :
            if visited[i] == 0 :
                visited[i] = 1
                start.append(i)
                removed_idx = link.index(i)
                link.remove(i)
                combination(i + 1, num)
                link.insert(removed_idx, i)
                visited[i] = 0
                start.pop()

for m in range(1, (n // 2) + 1) :
    combination(0, m)
print(minValue)