T = int(input())

for test_case in range(T) :
    a, b, c = map(int, input().split())
    # 등차인지 확인
    if (a - b == b - c) :
        print(f"#{test_case + 1} 0.0")
        continue

    front_gap = a - b
    tail_gap = b - c
    
    # 맨앞 바꾸기
    r1 = abs(tail_gap + b - a)
    r2 = abs(((a + c) / 2 - b))
    r3 = abs(2 * b - a - c)

    print(f"#{test_case + 1} {min(r1, r2, r3)}")