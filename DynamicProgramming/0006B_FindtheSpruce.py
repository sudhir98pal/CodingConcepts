# dp Q link-> https://codeforces.com/contest/1461/problem/B
t=int(input())
while t>0:
    t=t-1
    n,m=[int(x) for x in input().split()]
    s=[]
    for i in range(0,n):
        p=[]
        p[:0]=input()
        s.append(p)
    dp=[[0 for x in range(m)] for x in range(n)]
    
    for i in range(n):
        for j in range(m):
            if s[i][j]=='*':
                dp[i][j]=1
    for i in range(n-2,-1,-1):
        for j in range(1,m-1,1):
            if dp[i][j]>0:
                dp[i][j]=dp[i][j]+min(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])
    ans=0
    for i in range(0,n):
        for j in range(0,m):
            ans=ans+dp[i][j]
    print(ans)
