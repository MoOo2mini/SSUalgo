from bisect import bisect_left

while True:
    try :
        n = int(input())
        arr = list(map(int, input().split()))

        stack = [arr[0]]
        for i in range(1, n) :
            if stack[-1] < arr[i] :
                stack.append(arr[i])
            else :
                idx = bisect_left(stack, arr[i])
                stack[idx] = arr[i]
        print(len(stack))
    except EOFError :
        break