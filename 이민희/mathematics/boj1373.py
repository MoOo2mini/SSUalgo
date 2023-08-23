import sys, math
input = sys.stdin.readline

s = input().split()
s = s[0]

repeat = math.ceil(len(s) / 3)
num = 0
answer = []
for i in range(repeat) :
    if ((i * 3 + 1) <= len(s)) :
        num += int(s[-(i * 3 + 1)]) * 1
    if ((i * 3 + 2) <= len(s)) :
        num += int(s[-(i * 3 + 2)]) * 2
    if ((i * 3 + 3) <= len(s)) :
        num += int(s[-(i * 3 + 3)]) * 4
    answer.append(num)
    num = 0
answer.reverse()
print(*answer, sep='')