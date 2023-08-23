import sys
input = sys.stdin.readline

# def count_two(n) :
#     answer = 0
#     if n < 2 :
#         return answer

#     for i in range(1, n + 1) :
#         tmp_i = i
#         while tmp_i % 2 == 0 :
#             tmp_i //= 2
#             answer += 1
#     return answer


def count_five(n):
    """
    예시) n = 25인 경우,
    25 이하에서 5로 나눠 떨어지는 수 : 5개
    25 이하에서 5^2으로 나눠 떨어지는 수 : 1개

    총 6개!
    """
    answer = 0
    while n != 0:
        n = n // 5
        answer += n
    return answer

def count_two(n):
    answer = 0
    while n != 0:
        n = n // 2
        answer += n
    return answer

n, r = list(map(int, input().split()))

count2 = count_two(n) - count_two(n - r) - count_two(r)
count5 = count_five(n) - count_five(n - r) - count_five(r)
print(min(count2, count5))