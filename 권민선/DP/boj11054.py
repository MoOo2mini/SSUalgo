import sys


input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().split()))

re_arr = arr[::-1]

up = [1]*N

down = [1]*N

for i in range (1,N):
    for j in range(i):
        if arr[i]>arr[j]:
            up[i] = max(up[i], up[j]+1)
        if re_arr[i]>re_arr[j]:
            down[i] = max(down[i],down[j]+1)


result = [1]*N

for i in range(N):
    result[i]=up[i]+down[N-i-1] -1

print(max(result))
