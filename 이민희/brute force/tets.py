def f(s):
    global maxV
    # 맨 앞구슬과 맨 뒤구슬만 남았을 때의 총합을 구해서 최대값 비교
    if(len(arr) == 2):
        if(s > maxV):
            maxV = s
        return
    else:
        for i in range(1,len(arr)-1):
            # 선택한 구슬의 전, 후 값을 저장
            r = arr[i-1] * arr[i+1]
            temp = arr[i]
            # 선택한 구슬 제거해주기
            del arr[i]
            f(s + r)
            # 위에서 제거했던 구슬을 해당 위치에 다시 넣어주기
            arr.insert(i, temp)

n = int(input())
arr = list(map(int, input().split()))
maxV = 0
f(0)
print(maxV)