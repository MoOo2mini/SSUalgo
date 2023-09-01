import sys
input = sys.stdin.readline

def func(idx, num) :
    if num == m :
        ans.add(tuple(result))

    else :
        for i in range(0, n) :
            result.append(arr[i])
            func(i + 1, len(result))
            result.pop()

n, m = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.sort()
result = []
ans = set()
func(0, 0)

for i in sorted(list(ans)):
    print(*i)