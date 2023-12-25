import math

def calculate_gcd(a, b):
    result = a
    for i in range(a + 1, b + 1):
        result = math.gcd(result, i)
    return result

T = int(input())
for test_case in range(T) :
    # 사용자로부터 A와 B를 입력 받습니다.
    A, B = map(int, input().split())

    # A이상 B이하의 모든 자연수의 최대공약수를 계산합니다.
    result_gcd = calculate_gcd(A, B)

    # 결과를 출력합니다.
    print(f"#{test_case + 1} {result_gcd}")
