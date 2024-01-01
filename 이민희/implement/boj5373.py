def turn_clock_reverse_way(idx) :
    global cube
    cube[idx] = [list(x) for x in zip(*cube[idx])][::-1]

def turn_clock_way(idx) :
    global cube
    cube[idx] = [list(x) for x in zip(*(cube[idx][::-1]))]

def l_minus() :
    global cube
    turn_clock_reverse_way(3)
    o = [row[0] for row in cube[2]]
    w = [row[0] for row in cube[0]]
    r = [row[0] for row in cube[4]]
    y = [row[0] for row in cube[5]]

    for i in range(3) :
        cube[2][i][0] = w[i]
        cube[0][i][0] = r[i]
        cube[4][i][0] = y[i]
        cube[5][i][0] = o[i]

def l_plus() :
    global cube
    turn_clock_way(3)
    o = [row[0] for row in cube[2]]
    w = [row[0] for row in cube[0]]
    r = [row[0] for row in cube[4]]
    y = [row[0] for row in cube[5]]

    for i in range(3) :
        cube[4][i][0] = w[i]
        cube[5][i][0] = r[i]
        cube[2][i][0] = y[i]
        cube[0][i][0] = o[i]

def r_minus() :
    global cube
    turn_clock_reverse_way(1)
    o = [row[2] for row in cube[2]]
    w = [row[2] for row in cube[0]]
    r = [row[2] for row in cube[4]]
    y = [row[2] for row in cube[5]]

    for i in range(3) :
        cube[4][i][2] = w[i]
        cube[5][i][2] = r[i]
        cube[2][i][2] = y[i]
        cube[0][i][2] = o[i]
def r_plus() :
    global cube
    turn_clock_way(1)
    o = [row[2] for row in cube[2]]
    w = [row[2] for row in cube[0]]
    r = [row[2] for row in cube[4]]
    y = [row[2] for row in cube[5]]

    for i in range(3) :
        cube[2][i][2] = w[i]
        cube[0][i][2] = r[i]
        cube[4][i][2] = y[i]
        cube[5][i][2] = o[i]

def b_plus() :
    global cube
    turn_clock_way(2)
    w = cube[0][0]
    g = cube[3][0][::-1]
    y = cube[5][2][::-1]
    b = cube[1][0]

    cube[3][0] = w
    cube[0][0] = b
    cube[1][0] = y
    cube[5][2] = g

def b_minus() :
    global cube
    turn_clock_reverse_way(2)
    w = cube[0][0]
    g = cube[3][0]
    y = cube[5][2][::-1]
    b = cube[1][0][::-1]

    cube[3][0] = y
    cube[0][0] = g
    cube[1][0] = w
    cube[5][2] = b

def u_plus() :
    global cube
    turn_clock_way(0)
    r = cube[4][0]
    o = cube[2][2]
    b = [row[2] for row in cube[3]][::-1]
    g = [row[0] for row in cube[1]][::-1]

    for i in range(3) :
        cube[1][i][0] = o[i]
    cube[4][0] = g
    for i in range(3) :
        cube[3][i][2] = r[i]
    cube[2][2] = b

def u_minus() :
    global cube
    turn_clock_reverse_way(0)
    r = cube[4][0][::-1]
    o = cube[2][2][::-1]
    b = [row[2] for row in cube[3]]
    g = [row[0] for row in cube[1]]

    for i in range(3) :
        cube[1][i][0] = r[i]
    cube[2][2] = g
    for i in range(3) :
        cube[3][i][2] = o[i]
    cube[4][0] = b

def f_plus() :
    global cube
    turn_clock_way(4)
    b = cube[3][2]
    w = cube[0][2]
    g = cube[1][2][::-1]
    y = cube[5][0][::-1]

    cube[1][2] = w
    cube[5][0] = g
    cube[3][2] = y
    cube[0][2] = b

def f_minus() :
    global cube
    turn_clock_reverse_way(4)
    b = cube[3][2][::-1]
    w = cube[0][2]
    g = cube[1][2]
    y = cube[5][0][::-1]

    cube[1][2] = y
    cube[5][0] = b
    cube[3][2] = w
    cube[0][2] = g

def d_plus() :
    global cube
    r = cube[4][2][::-1]
    g = [row[0] for row in cube[3]]
    b = [row[2] for row in cube[1]]
    o = cube[2][0][::-1]

    turn_clock_way(5)
    for i in range(3) :
        cube[1][i][2] = r[i]
    cube[2][0] = b
    for i in range(3) :
        cube[3][i][0] = o[i]
    cube[4][2] = g

def d_minus() :
    global cube
    r = cube[4][2]
    g = [row[0] for row in cube[3]][::-1]
    b = [row[2] for row in cube[1]][::-1]
    o = cube[2][0]

    turn_clock_reverse_way(5)
    for i in range(3) :
        cube[1][i][2] = o[i]
    cube[4][2] = b
    for i in range(3) :
        cube[3][i][0] = r[i]
    cube[2][0] = g
t = int(input())
for _ in range(t) :
    n = int(input())
    commend = list(input().split())

    cube = [
        [['w'] * 3 for _ in range(3)],
        [['b'] * 3 for _ in range(3)],
        [['o'] * 3 for _ in range(3)],
        [['g'] * 3 for _ in range(3)],
        [['r'] * 3 for _ in range(3)],
        [['y'] * 3 for _ in range(3)],
    ]
    for i in range(n) :
        if commend[i] == 'L+' :
            l_plus()
        elif commend[i] == 'L-' :
            l_minus()
        elif commend[i] == 'R+' :
            r_plus()
        elif commend[i] == 'R-' :
            r_minus()
        elif commend[i] == 'U+' :
            u_plus()
        elif commend[i] == 'U-' :
            u_minus()
        elif commend[i] == 'D+' :
            d_plus()
        elif commend[i] == 'D-' :
            d_minus()
        elif commend[i] == 'F+' :
            f_plus()
        elif commend[i] == 'F-' :
            f_minus()
        elif commend[i] == 'B+' :
            b_plus()
        elif commend[i] == 'B-' :
            b_minus()
    for row in cube[0] :
        print(*row, sep='')

"""
4
12
D+ L+ B+ U+ R+ F+ D- L- B- U- R- F-
12
D- L- B- U- R- F- D+ L+ B+ U+ R+ F+
12
F+ R+ U+ B+ L+ D+ F- R- U- B- L- D-
12
F- R- U- B- L- D- F+ R+ U+ B+ L+ D+
"""