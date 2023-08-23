def factorial(n) :
    answer = 1
    for i in range(1, n + 1) :
        answer *= i
        answer %= 10000000000
        while answer % 10 == 0 :
            answer /= 10
    return (answer % 10)

t = int(input())
for i in range(t) :
    n = int(input())
    fact = factorial(n)
    print(int(fact))