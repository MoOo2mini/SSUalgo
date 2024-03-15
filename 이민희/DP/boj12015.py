# 입력 조건: 100만 -> O(n^2)의 시간 복잡도는 시간초과 판정이 나온다.
# 1억이 1초라고 하니.. 100만 * 100만은 10^12 = 10^8 * 10000이다. wow
from bisect import bisect_left, bisect_right

n = int(input())
a = list(map(int, input().split()))

stack = [a[0]]
for i in range(1, n) : 
    if (stack[-1] < a[i]) :
        stack.append(a[i])
    else :
        idx = bisect_left(stack, a[i])
        stack[idx] = a[i]

print(len(stack))
