# Author: yassjd199
#https://codeforces.com/contest/158/problem/C
 
from collections import deque
n =int(input())
q = deque()
l = []
for i in range(n) : 
    str = input().strip().replace(" ","")
    if(str== "pwd") : 
        print('/',end='')
        print(*q,sep='/',end='')
        if(len(q)): print('/',end='')
        print('')
    else :
        str = str[2:]
        if(str[0]=='/') : q.clear()
        l = str.strip('/').split('/')
        
        for x in l :
            if (x ==".." and len(q) !=0 ) : q.pop()
            elif(x!= "" ): q.append(x)
