//Q Link;->https://leetcode.com/problems/edit-distance/submissions/
class Solution {
public:
    int dp[1000][1000];
  
    int solve(string a,string b, int i,int j )
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(a[i-1]==b[j-1])
        {
            dp[i][j]=solve(a,b,i-1,j-1);
            return dp[i][j];
        }
        
        dp[i][j]=1+min(solve(a,b,i-1,j-1),min(solve(a,b,i-1,j),solve(a,b,i,j-1)));
        return dp[i][j];
        
        
    }
    int minDistance(string a, string b)
    {
        int n=a.size();
       int m=b.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        return solve(a,b,n,m);
    }
};
