 # Author: yassjd199
 #https://codeforces.com/contest/81/problem/A




from collections import deque

str = input()
q = deque()

for x in str:
    if (len(q)==0 or q[-1] != x) : q.append(x)
    else: q.pop()

print(*q,sep='')
