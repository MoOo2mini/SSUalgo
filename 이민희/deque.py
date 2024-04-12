from collections import deque

q = deque()
for i in range(10) :
    q.append(i)
print(q)
q.pop()
print(q)
q.popleft()
print(q)

for i in q :
    print(i)

dictionary = dict({1:2, 2:3, 4:10})
print(dictionary[1])

dictionary[3] = 9
print(dictionary)