"""
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5

첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)

둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다. (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.

"""

R, C, m = map(int, input().split())

sharks = {}
tmp_sharks = {}
get_shark_size = 0

def direct(d) :
    if d == 1 :
        return (-1, 0)
    elif d == 2:
        return (1, 0)
    elif d == 3:
        return (0, 1)
    elif d == 4:
        return (0, -1)

for _ in range(m) :
    r, c, s, d, z = map(int, input().split())
    sharks[(r - 1, c - 1)] = [s, direct(d), z]

for man in range(C) :
    # 현재 낚시꾼이 있는 열에 상어가 있는지 확인
    for y in range(R) :
        if ((y, man) in sharks) :
            # 상어가 있음.
            _, _, size = sharks[(y, man)]
            del sharks[(y, man)]
            get_shark_size += size
            break
    
    # 상어들의 이동
    for shark in sharks :
        r, c = shark
        s, d, z = sharks[shark]

        rr, cc = d
        currentR = r + (rr * s)
        currentC = c + (cc * s)
        
        while not (0 <= currentC < C and 0 <= currentR < R ) :
            if (currentR >= R) :
                tmp = currentR - (R - 1)
                currentR = (R - 1) - tmp
                rr *= -1
            elif (currentR < 0) :
                currentR *= -1
                rr *= -1
            elif (currentC >= C) :
                tmp = currentC - (C - 1)
                currentC = (C - 1) - tmp
                cc *= -1
            elif (currentC < 0) :
                currentC *= -1
                cc *= -1
        d = (rr, cc)
        
        # 같은 공간에 가게 되면? 
        if ((currentR, currentC) in tmp_sharks) :
            _, _, tmp_size = tmp_sharks[(currentR, currentC)]
            if (z > tmp_size) :
                tmp_sharks[(currentR, currentC)] = s, d, z
        else :
            tmp_sharks[(currentR, currentC)] = s, d, z
        
    # 이동 후 sharks 리셋.. 
    sharks = tmp_sharks
    tmp_sharks = {}

print(get_shark_size)