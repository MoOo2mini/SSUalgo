N = int(input())
T = []
P = []

for _ in range(N) :
    a, b = map(int, input().split())
    T.append(a)
    P.append(b)

maxValue = 0
def dfs(currentDay, p) :
    global maxValue
    if (currentDay[-1] > N) :
        maxValue = max(p, maxValue)
        return

    # 일을 하는 경우
    if (currentDay[-1] + T[currentDay[-1] - 1] <= N + 1) :
        tmp = currentDay[:]
        tmp.append(currentDay[-1] + T[currentDay[-1] - 1])
        dfs(tmp, p + P[currentDay[-1] - 1])
    # 일을 하지 않는 경우
    tmp = currentDay[:]
    tmp.append(currentDay[-1] + 1)
    dfs(tmp, p)

dfs([1], 0)
print(maxValue)