n = int(input())

graph = []
for _ in range(n) :
    a, b = map(int, input().split())
    graph.append([a, b])
inf = int(1e9)
dp = [[inf] * (1 << n) for _ in range(n)]
 
import math
def tsp(x, y, visited) :
    if visited == ((1 << n) - 1) :
        if (graph[x][0] == 0) :
            return inf
        if (graph[x][0] != 0) :
            return graph[x][0]
        
    if dp[x][visited] != inf : # 이미 최소경로가 되어있으면 pass
        return dp[x][visited]

    for i in range(1, n) :
        # 만약 경로가 없으면 패스
        if graph[x][i] == 0 :
            continue
        if ((1 << i) & visited) != 0 : # 방문했던 도시라면
            continue
        dp[x][visited] = min(dp[x][visited], tsp(i, x, visited | (1 << i)) + calculate(x, y))
    return dp[x][visited]

def calculate(x, y) :
    xa, xb = graph[x]
    ya, yb = graph[y]
    return math.sqrt((xa - ya) ** 2 + (xb - yb) ** 2)
    
print(tsp(0, 0, 1))
