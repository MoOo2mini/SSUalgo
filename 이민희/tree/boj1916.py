INF = 100000001
n = int(input())
m = int(input())
graph = [[INF for _ in range(n+1)] for _ in range(n+1)]

# 최단 거리들을 저장하는 역할
d = [INF for _ in range(n+1)]

# 방문했는지 아닌지 저장하는 역할
visit = [False for _ in range(n+1)]

def minIndex():
    minValue = INF
    idx = 0
    for i in range(1, n+1):
        if not visit[i] and minValue > d[i] :
            minValue = d[i]
            idx = i
    return idx

def dijkstra(x):
    for i in range(1, n+1) :
        d[i] = graph[x][i]
    visit[x] = True

    for _ in range(n - 2) :
        x = minIndex() # 현재 노드에서 가장 짧은 거리로 갈 수 있는 거리를 반환
        visit[x] = True
        for i in range(1, n+1) :
            if not visit[i] and graph[x][i] + d[x] < d[i] :
                d[i] = graph[x][i] + d[x]
    print(d[e])

for _ in range(m) :
    a, b, c = map(int, input().split())
    graph[a][b] = min(graph[a][b], c)

s, e = map(int, input().split())

dijkstra(s)