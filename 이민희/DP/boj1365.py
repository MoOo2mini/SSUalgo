from bisect import bisect_left

def front(arr, n) :
    stack = [arr[0]]
    for i in range(1, n) :
        if stack[-1] < arr[i] :
            stack.append(arr[i])
        else :
            idx = bisect_left(stack, arr[i])
            stack[idx] = arr[i]
    return len(stack)

n = int(input())
arr = []
for _ in range(n) :
    tmp = int(input())
    arr.append(tmp)

print(max(front(arr, n), front(arr[::-1], n)))
