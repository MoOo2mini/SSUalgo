import sys
input = sys.stdin.readline

n, b = list(map(int, input().split()))

answer = ''
while n != 0 :
    mod = n % b
    n = n // b

    if (mod > 9) :
        mod = chr(ord('A') + mod - 10)
    else :
        mod = str(mod)
    answer += mod
print(answer[::-1])