import sys
input = sys.stdin.readline

def func(idx, num) :
    if num == m :
        # not_same = False
        # for result_idx in range(m) :
        #     if before_value[result_idx] != result[result_idx] : 
        #         not_same = True
        #         before_value[result_idx] = result[result_idx]
        # if not_same :
        ans.add(tuple(result))

    else :
        for i in range(idx, n) :
            if num == 0 :
                visited[i] = 1
                result.append(arr[i])
                func(i + 1, 1)
                visited[i] = 0
                result.pop()
            elif visited[i] == 0 and result[-1] <= arr[i]:
                visited[i] = 1
                result.append(arr[i])
                func(i + 1, len(result))
                visited[i] = 0
                result.pop()

n, m = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.sort()
result = []
before_value = [0] * m
visited = [0] * n
ans = set()
func(0, 0)

for i in sorted(list(ans)):
    print(*i)