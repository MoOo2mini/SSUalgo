n = int(input())
numbers = list(map(int, input().split()))
cc = '+-*/'
arr = []
add, minus, mul, div = list(map(int, input().split()))

minValue = 1e10 + 1
maxValue = -1e10 - 1

tmp_result = numbers[0]

def permutation(result, depth, add, minus, mul, div) :
    global maxValue, minValue
    if depth == n - 1 :
        minValue = min(minValue, result)
        maxValue = max(maxValue, result)
        return
    
    if add > 0 :
        permutation(result + numbers[depth + 1], depth + 1, add - 1, minus, mul, div)
    if minus > 0 :
        permutation(result - numbers[depth + 1], depth + 1, add, minus - 1, mul, div)
    if mul > 0 :
        permutation(result * numbers[depth + 1], depth + 1, add, minus, mul - 1, div)
    if div > 0 :
        tmp = result
        if tmp < 0 :
            tmp = abs(tmp) // abs(numbers[depth + 1])
            tmp *= -1
        else :
            tmp //= numbers[depth + 1]
        permutation(tmp, depth + 1, add, minus, mul, div - 1)

permutation(numbers[0], 0, add, minus, mul, div)
print(maxValue)
print(minValue)