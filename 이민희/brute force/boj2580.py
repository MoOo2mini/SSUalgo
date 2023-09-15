arr = []
for _ in range(9) :
    arr.append(list(map(int, input().split())))

def check(row, col) :
    return

for i in range(9) :
    for j in range(9) :
        if arr[i][j] == 0 :
            check(i, j)