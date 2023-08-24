import sys
input = sys.stdin.readline

n, b = input().split(' ')
b = int(b)

n = n[::-1]
base = 1

answer = 0

for i in n :
    if (i >= 'A' and i <= 'Z') :
        answer += (ord(i) - ord('A') + 10) * base
    else :
        answer += (ord(i) - ord('0')) * base
    base *= b

print(answer)