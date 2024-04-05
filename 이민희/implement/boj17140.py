def func(arr) :
    tmp = []
    for a in arr :
        if (a != 0) :
            tmp.append(a)
    arr = tmp

    tmp = set()
    for i in arr :
        tmp.add((i, arr.count(i)))

    tmp = list(map(list, tmp))
    tmp = sorted(tmp, key=lambda x : (x[1], x[0]))
    arr = sum(tmp, [])
    return arr

r, c, k = map(int, input().split())
arr = []
for _ in range(3) :
    arr.append(list(map(int, input().split())))

minute = 0
while minute <= 100 :
    rowCnt = len(arr)
    colCnt = len(arr[0])
    if (0 <= r <= rowCnt) and (0 <= c <= colCnt) :
       if (arr[r - 1][c - 1] == k) :
            break
    if (rowCnt >= colCnt) :
        # R연산 적용
        maxlen = 0
        maxidx = 0
        for i in range(len(arr)) :
            tmp = func(arr[i])
            arr[i] = tmp
            if (len(tmp) > maxlen) :
                maxidx = i
                maxlen = len(tmp)

        # 가장 큰 행을 기준으로 0으로 채움.
        for i in range(len(arr)) :
            if (len(arr[i]) != maxlen) :
                zero = maxlen - len(arr[i])
                arr[i] = sum([arr[i], [0 for _ in range(zero)]], [])

    else :
        # C연산 적용
        colArr = list(map(list, zip(*arr)))
        tmpArr = []

        maxlen = 0
        maxidx = 0
        for i in range(len(colArr)) :
            tmpArr.append(func(colArr[i]))
            if (len(tmpArr[i]) > maxlen) :
                maxidx = i
                maxlen = len(tmpArr[i])
        # 가장 큰 행을 기준으로 0으로 채움.
        for i in range(len(tmpArr)):
            if (len(tmpArr[i]) != maxlen):
                zero = maxlen - len(tmpArr[i])
                tmpArr[i] = sum([tmpArr[i], [0 for _ in range(zero)]], [])
        arr = list(map(list, zip(*tmpArr)))

    if (len(arr) > 100) :
        arr = arr[0:100]
    if (len(arr[0]) > 100) :
        arr = [arr[i][0:100] for i in range(len(arr))]
    minute += 1

if (minute > 100) :
    print(-1)
else :
    print(minute)

