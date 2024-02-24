wheels = []

def turn_clock_way(wheel_num) :
    global wheels
    tmp = wheels[wheel_num].pop()
    wheels[wheel_num].insert(0, tmp)

def turn_clock_reverse_way(wheel_num) :
    global wheels
    tmp = wheels[wheel_num].pop(0)
    wheels[wheel_num].append(tmp)

def turn_wheel(wheel_num, direction, left, right) :
    global wheels
    current_2 = wheels[wheel_num][2]
    current_6 = wheels[wheel_num][6]
    if (direction == -1) :
        turn_clock_reverse_way(wheel_num)
    else :
        turn_clock_way(wheel_num)
    # 왼쪽
    left_num = wheel_num - 1
    if (0 <= left_num < 4 and left == 1) :
        if (wheels[left_num][2] != current_6) :
            if (direction == -1) :
                turn_wheel(left_num, 1, 1, 0)
            elif (direction == 1) :
                turn_wheel(left_num, -1, 1, 0)

    right_num = wheel_num + 1
    if (0 <= right_num < 4 and right == 1) :
        if (wheels[right_num][6] != current_2) :
            if (direction == -1) :
                turn_wheel(right_num, 1, 0, 1)
            elif (direction == 1) :
                turn_wheel(right_num, -1, 0, 1)

for _ in range(4) :
    tmp = list(input())
    tmp = list(map(int, tmp))
    wheels.append(tmp)

k = int(input())
for _ in range(k) :
    wheel_num, direction = map(int, input().split())
    turn_wheel(wheel_num - 1, direction, 1, 1)

result = sum([wheels[i][0] * (2 ** i) for i in range(4)])
print(result)