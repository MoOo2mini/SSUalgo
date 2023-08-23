import sys, math
input = sys.stdin.readline

def GCD(a, b) :
    while b != 0 :
        a, b = b, a % b
    return a

n, s = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.append(s)

arr.sort()

if n == 1 :
    print(arr[1] - arr[0])
else :
    distance = []
    for i in range(1, n + 1) :
        distance.append(arr[i] - arr[i - 1])

    gcd = distance[0]
    for i in range(1, len(distance)) :
        gcd = GCD(distance[i], gcd)

    print(gcd)