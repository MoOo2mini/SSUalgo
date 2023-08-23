t = int(input())
def func(a, b) :
    num1 = a
    num2 = b

    while num1 != num2 :
        if (num1 > num2) :
            num2 += b
        elif (num1 < num2) :
            num1 += a

    return num1

for i in range(t) :
    a, b = list(map(int, input().split(' ')))
    print(func(a, b))