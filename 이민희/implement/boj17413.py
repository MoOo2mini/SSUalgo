from collections import deque

# tmpstr = input().split()
tmpstr = input()
str = []
result = []
tmp = ''
tag = False
for s in tmpstr :
    if (s == '<') :
        tag = True
    if (s == '>') :
        tag = False
    
    if (not tag and s == ' ') :
        str.append(tmp)
        tmp = ''
    if (tag) :
        tmp += s
    if (not tag and s != ' ') :
        tmp += s
if (tmp != '') :
    str.append(tmp)

for s in str :
    if ('<' not in s) :
        result.append(s[::-1])
    else :
        tmp = ''
        dp = deque()
        i = 0
        while (i < len(s)) :
            if (s[i] != '<') :
                dp.append(s[i])
            if (s[i] == '<') :
                while dp :
                    tmp += dp.pop()
                tmp += '<'
                i += 1
                while (s[i] != '>') :
                    tmp += s[i]
                    i += 1
                tmp += '>'
            i += 1
        while dp:
            tmp += dp.pop()
        # print(tmp)
        result.append(tmp)

print(*result, sep=' ')