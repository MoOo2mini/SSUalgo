import sys
input = sys.stdin.readline

n = int(input())
arr = list(x for x in range(n))
map_list = []
for _ in range(n) :
    map_list.append(list(map(int, input().split())))

result = []
visited = [0] * n

def func(idx, num, current_num) :
    global min_num
    if min_num <= current_num :
        return
    elif num == n and map_list[result[-1]][result[0]] != 0 :
        current_num += map_list[result[-1]][result[0]]
        min_num = min(min_num, current_num)
    elif min_num <= current_num :
        return
    else :
        for i in range(0, n) :
            if visited[i] == 0 :
                tmp = current_num
                result.append(arr[i])
                visited[i] = 1
                if len(result) > 1 : 
                    tmp += map_list[result[-2]][i]
                    if map_list[result[-2]][i] != 0 :
                        func(i + 1, num + 1, tmp)
                else :
                    func(i + 1, num + 1, tmp)
                result.pop()
                visited[i] = 0

min_num = 1000000 * 10 + 1
func(0, 0, 0)
print(min_num)