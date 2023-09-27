arr = []
for _ in range(9) :
    arr.append(list(map(int, input().split())))

def make_no_zero() :
    global arr
    for i in range(9) :
        for j in range(9) :
            if arr[i][j] == 0:
                if (arr[i].count(0) == 1) :
                    arr[i][j] = 45 - sum(arr[i])
                    i += 1
                    continue;

                col_list = []
                for t in range(9) :
                    col_list.append(arr[t][j])
                if (col_list.count(0) == 1) :
                    arr[i][j] = 45 - sum(col_list)
                    continue;

                nine_list = []
                for n in range((i // 3) * 3, (i // 3) * 3 + 3) :
                    for m in range((j // 3) * 3, (j // 3) * 3 + 3) :
                        nine_list.append(arr[n][m])
                if (nine_list.count(0) == 1) :
                    arr[i][j] = 45 - sum(nine_list)
                    continue;


is_zero = True
while is_zero :
    is_zero = False
    for row in arr :
        if (row.count(0) > 0) :
            is_zero = True
            break
    if is_zero :
        make_no_zero()

for row in arr :
    print(*row)


# 0 3 5 4 6 9 2 7 8
# 7 0 0 1 0 5 6 0 9
# 0 6 0 2 7 8 1 3 5
# 3 2 1 0 4 6 8 9 7
# 8 0 4 9 1 0 5 0 6
# 5 9 6 8 0 0 4 1 3
# 9 1 7 6 5 2 0 8 0
# 6 0 3 7 0 1 9 0 0
# 2 5 8 3 9 4 7 6 0