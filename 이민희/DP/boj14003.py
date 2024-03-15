from bisect import bisect_left

n = int(input())
a = list(map(int, input().split()))

stack = [a[0]]
lenRecord = [0] * n
lenRecord[0] = 1

for i in range(1, n) :
    if (stack[-1] < a[i]) :
        stack.append(a[i])
        lenRecord[i] = len(stack)
    else :
        idx = bisect_left(stack, a[i])
        stack[idx] = a[i]
        lenRecord[i] = idx + 1

maxLen = len(stack)
answer = []

print(lenRecord)
print(stack)
for i in range(len(lenRecord) - 1, -1, -1) :
    # i : 현재 a[i]를 가리키고 있음.
    if (lenRecord[i] == maxLen) :
        answer.append(a[i])
        maxLen -= 1
    if maxLen < 1 :
        break

print(len(stack))
print(*(answer[::-1]))