n = int(input())
if (n == 0) :
    print('0')
else :
    answer = ''
    while n != 0 :
        mod = n % -2
        if not (mod == 0 or mod == 1) :
            mod = 1
            n -= 1
        n = n // -2

        answer += str(mod)
    print(answer[::-1])