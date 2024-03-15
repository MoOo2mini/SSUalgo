from bisect import bisect_left
n = int(input())
arr = []
sequence = []
lenRecord = [0] * n
lenRecord[0] = 1
for _ in range(n) :
    a, b = map(int, input().split())
    arr.append((a, b))

arr.sort()

for i in range(n) :
    _, b = arr[i]
    sequence.append(b)
stack = [sequence[0]]

for i in range(1, n) :
    if (stack[-1] < sequence[i]) :
        stack.append(sequence[i])
        lenRecord[i] = len(stack)
    else :
        idx = bisect_left(stack, sequence[i])
        stack[idx] = sequence[i]
        lenRecord[i] = idx + 1

answer = []
maxLen = len(stack)

for i in range(len(lenRecord) - 1, - 1, -1) :
    if (maxLen == lenRecord[i]) :
        tmp, _ = arr[i]
        answer.append(tmp)
        maxLen -= 1
    if (maxLen < 1) :
        break

tmp = set(answer)

print(n - len(tmp))
for i in range(n) :
    a, _ = arr[i]
    if a not in answer :
        print(a)