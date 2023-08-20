from collections import Counter, deque

n = int(input())
arr = list(map(int, input().split(' ')))

counter = Counter(arr)
stack = deque()
answer = [-1] * n

for i in range(n) :
    while (stack and stack[-1][1] < counter[arr[i]]) :
        tmp, fai, idx = stack.pop()
        answer[idx] = arr[i]
    stack.append([arr[i], counter[arr[i]], i])

print(*answer)