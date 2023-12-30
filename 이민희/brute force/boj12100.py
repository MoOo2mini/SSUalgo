import copy

n = int(input())
origin_arr = []

for _ in range(n) :
    origin_arr.append(list(map(int, input().split())))

def carculate_up(origin_arr) :
    global n
    arr = copy.deepcopy(origin_arr)
    for i in range(n) :
        for j in range(n) :
            idx = 1
            while ((j + idx) < n and arr[j + idx][i] == 0) :
                idx += 1
            if ((j + idx) < n and arr[j][i] == arr[j + idx][i]) :
                arr[j][i] += arr[j + idx][i]
                arr[j + idx][i] = 0

    for i in range(n) :
        tmp = [0] * n
        idx = 0
        for j in range(n) :
            if (arr[j][i] != 0) :
                tmp[idx] = (arr[j][i])
                idx += 1
        for j in range(n) :
            arr[j][i] = tmp[j]
    return arr

def carculate_down(origin_arr) :
    global n
    arr = copy.deepcopy(origin_arr)[::-1]
    return carculate_up(arr)[::-1]

def carculate_left(origin_arr) : 
    global n
    arr = copy.deepcopy(origin_arr[::-1])
    arr = carculate_up([list(x) for x in zip(*arr)])
    return ([list(x) for x in zip(*arr)][::-1])

def carculate_right(origin_arr) :
    global n
    arr = copy.deepcopy(origin_arr[::-1])
    arr = carculate_down([list(x) for x in zip(*arr)])
    return ([list(x) for x in zip(*arr)][::-1])

func_list = [carculate_up, carculate_down, carculate_left, carculate_right]

visited = set()

q = []
q.append([origin_arr, 0])
visited.add(tuple(sum(origin_arr, [])))

maxValue = 0
while (q) :
    current_arr, cnt = q.pop(0)
    if (cnt + 1 > 5) :
        continue
    for func in func_list :
        new_arr = func(current_arr)
        if tuple(sum(new_arr, [])) not in visited :
            q.append([new_arr, cnt + 1])
        maxValue = max(maxValue, max(sum(new_arr, [])))
print(maxValue)