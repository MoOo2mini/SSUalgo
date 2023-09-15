import itertools

n = int(input())
numbers = list(map(int, input().split()))

arr = []
cc = '+-*/'
n_iters = list(map(int, input().split()))
for i in range(4) :
    num = n_iters[i]
    for _ in range(num) :
        arr.append(cc[i])

nPr = set(itertools.permutations(arr, len(arr)))

minValue = 1e10 + 1
maxValue = -1e10 - 1

for iter in nPr :
    tmp = numbers[0]
    for num_idx in range(1, n) :
        iter_idx = num_idx - 1
        if iter[iter_idx] == '+' :
            tmp += numbers[num_idx]
        elif iter[iter_idx] == '-' :
            tmp -= numbers[num_idx]
        elif iter[iter_idx] == '*' :
            tmp *= numbers[num_idx]
        elif iter[iter_idx] == '/' :
            if tmp < 0 :
                tmp = abs(tmp) // abs(numbers[num_idx])
                tmp *= -1
            else :
                tmp //= numbers[num_idx]
    minValue = min(minValue, tmp)
    maxValue = max(maxValue, tmp)

print(maxValue)
print(minValue)