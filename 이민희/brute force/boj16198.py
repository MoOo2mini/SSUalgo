from collections import deque
import copy
dp = deque()

n = int(input())
wlist = list(map(int, input().split()))
energy = 0
for x in range(1, n - 1) :
    tmp = wlist.pop(x)
    dp.append([wlist[x] * wlist[x - 1], copy.deepcopy(wlist)])
    wlist.insert(x, tmp)

while dp :
    tmp_energy, tmp_list = dp.popleft()
    if (len(tmp_list) == 2) :
            energy = max(energy, tmp_energy)
    # if (len(tmp_list) == 2) :
    #     energy = max(energy, tmp_energy)
    for x in range(1, len(tmp_list) - 1) :
        tmp = tmp_list.pop(x)
        if (len(tmp_list) == 2) :
            tmp_energy += tmp_list[x] * tmp_list[x - 1]
            energy = max(energy, tmp_energy)
        else :
            dp.append([tmp_energy + tmp_list[x] * tmp_list[x - 1], copy.deepcopy(tmp_list)])
        tmp_list.insert(x, tmp)

print(energy)