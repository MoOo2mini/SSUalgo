import sys
input = sys.stdin.readline

a, b = list(map(int, input().split()))
m = int(input())
arr = list(map(int, input().split()))

arr.reverse()

# first, convert to base10 number
base = 1
num10 = 0
for i in arr :
    num10 += i * base
    base *= a

# second, convert to baseB number
answer = []

while num10 != 0 :
    mod = num10 % b
    num10 //= b

    answer.append(mod)

answer.reverse()
print(*answer)