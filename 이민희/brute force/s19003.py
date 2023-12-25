'''
      아래의 구문은 input.txt 를 read only 형식으로 연 후,
      앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
      여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
      아래 구문을 이용하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.

      따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 구문을 사용하셔도 좋습니다.
      아래 구문을 사용하기 위해서는 import sys가 필요합니다.

      단, 채점을 위해 코드를 제출하실 때에는 반드시 아래 구문을 지우거나 주석 처리 하셔야 합니다.
'''
#import sys
#sys.stdin = open("input.txt", "r")

def check_pel(str, n) :
    start_idx = 0
    tail_idx = n - 1
    while (start_idx < tail_idx) :
        if (str[start_idx] != str[tail_idx]) :
            return False
        start_idx += 1
        tail_idx -= 1
    return True

def reverse_str(str, n) :
    result_str = ""
    for i in range(n - 1, -1, -1) :
        result_str += str[i]
    return result_str
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n, m = map(int, input().split())
    str_list = []
    reverse_list = []
    pel_tf_list = [False] * 100
    not_matched_pel = False
    matched_pel = 0
    for _ in range(n) :
        str_list.append(input())
        reverse_list.append(reverse_str(str_list[_], m))
    
    for i in range(n) :
        try :
            index = reverse_list.index(str_list[i])
            if (i == index) :
                not_matched_pel = True
                pel_tf_list[i] = True
            elif (pel_tf_list[i] == False and pel_tf_list[index] == False) :
                matched_pel += 1
                pel_tf_list[i] = True
                pel_tf_list[index] = True
        except ValueError :
            # 펠린드롬이 아님.
            continue
    
    result = (matched_pel * 2 * m)
    if not_matched_pel :
        result += m
    print(f"#{test_case} {result}")