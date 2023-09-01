import sys, copy
input = sys.stdin.readline

l, C = list(map(int, input().split()))
arr = list(input().split())

vowel = 'aeiou'
vowel_arr = []
not_vowel_arr = []
for c in arr :
    if c in vowel :
        vowel_arr.append(c)
    else :
        not_vowel_arr.append(c)

vowel_arr.sort()
not_vowel_arr.sort()

visited = [0] * C
result = []

vowel_list = []
not_vowel_list = []

my_result = []

def pick_arr(arr, idx, num) :
    if len(result) == num :
        if result[0] in vowel :
            vowel_list.append(copy.deepcopy(result))
        else :
            not_vowel_list.append(copy.deepcopy(result))

    else :
        for i in range(idx, len(arr)) :
            if visited[i] == 0 :
                result.append(arr[i])
                visited[i] = 1
                pick_arr(arr, i + 1, num)
                result.pop()
                visited[i] = 0

for i in range(2, l) :
    vowel_num = l - i
    not_vowel_num = i

    pick_arr(vowel_arr, 0, vowel_num)
    pick_arr(not_vowel_arr, 0, not_vowel_num)

    for n in vowel_list : 
        for m in not_vowel_list :
            word = n + m
            word.sort()
            # print(*word)
            my_result.append(word)

    vowel_list.clear()
    not_vowel_list.clear()

my_result.sort()
for i in my_result :
    print(*i, sep='')
