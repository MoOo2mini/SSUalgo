diceList = list(map(int, input().split()))
#
# arr_score = [[0, 2, 4, 6, 8, 10],
#         [13, 16, 19, 25, 30, 35, 40, -1],
#        [12, 14, 16, 18, 20],
#         [22, 24, 25, 30, 35, 40, -1],
#        [22, 24, 26, 28, 30],
#         [28, 27, 26, 25, 30, 35, 40, -1],
#        [32, 34, 36, 38, 40, -1]]

# 만약 시작 칸이라면 adj[idx][-1]로 하면 항상 맨뒤의 것으로 시작을 할 수 있음!
#       0   1   2   3   4   5      6   7   8   9    10      11   12   13   14   15      16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33   34   35   36
adj = [[1],[2],[3],[4],[5],[6,21],[7],[8],[9],[10],[11,27],[12],[13],[14],[15],[16,29],[17],[18],[19],[20],[32],[22],[23],[24],[25],[26],[20],[28],[24],[30],[31],[24],[32],[32],[32],[32],[32]]
# score는 0점부터 시작
score =[0,  2,  4,  6,  8,  10,    12, 14, 16, 18,  20,     22,  24,  26,  28,  30,     32,  34,  36,  38,  40,  13,  16,  19,  25,  30,  35,  22,  24,  28,  27,  26,  0]

# 현재 인덱스
def setYx(idx, diceN) :
    veryNext = adj[idx][-1]
    diceN -= 1

    while diceN != 0 :
        diceN -= 1
        veryNext = adj[veryNext][0]

    return (veryNext, score[veryNext])

# def setYx2(cy, cx, diceN) :
#     num = arr[cy][cx]
#     if (num == 10 or num == 20 or num == 30) and cy % 2 == 0 :
#         if (len(arr[cy]) == cx + 1) :
#             cy += 1
#             cx = diceN - 1
#             return (cy, cx)
#     else :
#         cx += diceN
#         if (cx >= len(arr[cy])) :
#             # 먼저 끝이 도착지점인지 확인
#             if (arr[cy][-1] == -1) :
#                 return (1, 7)
#             else :
#                 overNum = cx - len(arr[cy])
#                 cy += 2
#                 cx = overNum
#                 return (cy, cx)
#         else :
#             return (cy, cx)
#
#     return (cy, cx)

# 4개의 말의 위치, 몇번째 움직임인지, 현재 점수
pair = [0, 0, 0, 0]
maxScore = 0

def dfs(dots, cnt, score) :
    global maxScore
    if cnt == 10 :
        maxScore = max(score, maxScore)
        return

    for i in range(4) :
        idx = dots[i]
        if idx == 32 :
            continue
        nextIdx, s = setYx(idx, diceList[cnt])
        tmp = dots[:]
        tmp[i] = nextIdx

        # 도착한 말이면
        if (nextIdx == 32):
            dfs(tmp, cnt + 1, score)

        canDo = True
        # 만약 이미 다른말과 일치한다면 패스
        for m in range(4):
            if m != i:
                if dots[m] == nextIdx:
                    canDo = False
                    break
        if canDo :
            dfs(tmp, cnt + 1, score + s)

dfs(pair, 0, 0)
print(maxScore)
