n, l = map(int, input().split())
arr = []

for _ in range(n) :
    arr.append(list(map(int, input().split())))

def check(row) :
    global n, l
    slide = [0] * n
    for i in range(1, n) :
        if (row[i] != row[i - 1]) :
            if ((row[i] - row[i - 1]) == 1) :
                for ll in range(1, l + 1) :
                    idx = i - ll
                    if (0 <= idx < n) :
                        if (row[idx] != row[i] - 1) :
                            return False
                        if (slide[idx] == 1) :
                            return False
                    else :
                        return False
                for ll in range(1, l + 1) :
                    slide[i - ll] = 1
            elif ((row[i] - row[i - 1]) == -1) :
                for ll in range(l) :
                    idx = i + ll
                    if (0 <= idx < n) :
                        if (row[idx] != row[i]) :
                            return False
                        if (slide[idx] == 1) :
                            return False
                    else :
                        return False
                for ll in range(l) :
                    slide[i + ll] = 1
            else :
                return False

    return True


result = 0
for row in arr :
    if (check(row)) :
        result += 1

for col in range(n) :
    row = [arr[i][col] for i in range(n)]
    if (check(row)) :
        result += 1

print(result)