# q link->https://codeforces.com/contest/1454/problem/C

t=int(input())
while t>0:
    t=t-1
    n=int(input())
    mp=[1 for i in range(0,n+1)]
    arr=[int(x)  for x in input().split()]
    l=[]
    l.append(arr[0])
    for i in range(0,n):
        if(l[len(l)-1]!=arr[i]):
            l.append(arr[i])

    
    for i in l:
        mp[i]=mp[i]+1
        
    ans=2000000
    mp[l[0]]=mp[l[0]]-1
    mp[l[len(l)-1]]= mp[l[len(l)-1]]-1
    for i in range(0,len(l)):
      

            ans=min(ans,mp[l[i]])    
    print(ans)        






            
   


