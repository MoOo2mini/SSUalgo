n, m, h = map(int, input().split())
arr = [[0] * n for _ in range(h)]

for _ in range(m) :
    a, b = map(int, input().split())
    arr[a - 1][b - 1] = 1

def dfs(y, x, cnt) :
    global arr, ans
    if check(): # 현재 상태에서 각 출발점이 도착점으로 잘 도착하는지 확인
        ans = min(ans, cnt)
        return
    elif cnt == 3 or ans <= cnt: # 도착점이 정상적이지 않으면
        return
    for i in range(y, h) :
        if i == y :
            k = x
        else :
            k = 0
        for j in range(k, n - 1) :
            right_x = j + 1
            if arr[i][j] == 1 :
                continue
            if (arr[i][right_x] == 0) :
                if j > 0 and arr[i][j - 1] == 1 :
                    continue
                arr[i][j] = 1
                dfs(i, j + 2, cnt + 1)
                arr[i][j] = 0

def check() :
    global arr
    for current_line_num in range(n) :
        left_num = current_line_num - 1
        right_num = current_line_num

        for i in range(h) :
            if (0 <= left_num < (n - 1) and arr[i][left_num] == 1) :
                left_num -= 1
                right_num -= 1
            elif (0 <= right_num < (n - 1) and arr[i][right_num] == 1) :
                left_num += 1
                right_num += 1
        # print(current_line_num, " -> ", right_num)
        if (current_line_num != right_num) :
            return False
    return True

ans = 4
dfs(0, 0, 0)
print(ans if ans < 4 else -1)