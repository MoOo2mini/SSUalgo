n = int(input())
str = input()
arr = []

for i in range(n) :
    arr.append(int(input()))

from collections import deque
stack = deque()

for i in str :
    if (i <= 'Z' and i >= 'A') :
        idx = ord(i) - ord('A')
        stack.append(arr[idx])
    if i in '*/+-' :
        b = stack.pop()
        a = stack.pop()

        if i == '*' :
            stack.append(a * b)
        elif i == '/' :
            stack.append(a / b)
        elif i == '+' :
            stack.append(a + b)
        elif i == '-' :
            stack.append(a - b)

print("{:.2f}".format(stack[-1]))