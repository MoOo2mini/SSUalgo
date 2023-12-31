n = int(input())
arr = list(map(int, input().split()))

b, c = map(int, input().split())

cnt = 0
for i in range(n) :
    people = arr[i]

    if (people > 0 and people <= b) :
        arr[i] = 0
        cnt += 1
        continue
    else :
        people -= b
        cnt += 1
        if (people % c != 0) :
            cnt += ((people // c) + 1)
        elif (people % c == 0) :
            cnt += (people // c)
print(cnt)