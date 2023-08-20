str = input('')

from collections import deque

answer = 0
dq = deque()

for i in range(len(str)) :
    # 레이저라면
    if (dq and str[i - 1] == '(' and str[i] == ')') :
        dq.pop()
        answer += len(dq)
    elif (str[i] == '(') :
        dq.append('(')
    # 닫히는 경우
    elif (str[i - 1] != '(' and str[i] == ')' and dq[-1] == '(') :
        dq.pop()
        answer += 1

print(answer)