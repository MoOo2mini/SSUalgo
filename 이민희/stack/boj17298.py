n = int(input())
a = list(map(int, input().split(' ')))

from collections import deque

stack = deque()
answer = [-1] * n

for i in range(n) :
    while stack and (stack[-1][0] < a[i]) :
        tmp, idx = stack.pop()
        answer[idx] = a[i]
    stack.append([a[i], i])

print(*answer)
