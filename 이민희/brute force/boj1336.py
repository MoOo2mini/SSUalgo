n = int(input())
arr = []
alpha = {chr(x) : 0 for x in range(ord('A'), ord('Z') + 1)}

answer = 0

for _ in range(n) :
    tmp = input()
    for idx in range(len(tmp)) :
        mul_number = len(tmp) - 1 - idx
        alpha[tmp[idx]] += 10 ** mul_number

alpha = sorted(alpha.items(), key=lambda x: x[1])
alpha = alpha[::-1]

standard = 9
for c, num in alpha :
    answer += num * standard
    standard -= 1

print(answer)