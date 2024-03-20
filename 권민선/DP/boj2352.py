import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

result =[]

for i in arr:
    if not result or result[-1]<i:
        result.append(i)
    else:
        result[bisect_left(result,i)]=i


print(len(result))