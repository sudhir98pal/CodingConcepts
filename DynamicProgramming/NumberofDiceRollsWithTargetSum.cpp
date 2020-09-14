// Q link->https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#define mod 1000000007
#define ll  long long int

ll dp[35][1005];
class Solution {
public:
       ll dfs(ll d,ll f,ll x)
    {     if(x==0&&d==0) return 1;
     
        if(d==0||x<0) return 0;
     
     ll sum=0;
     if(dp[d][x]!=-1)
     {
         return dp[d][x];
     }
        for(ll i=1;i<=f;i++)
        {
            
    sum=(sum+dfs(d-1,f,x-i))%mod;
                 
        }
        
        return dp[d][x]=sum;
    }
    int numRollsToTarget(int d, int f, int tar)
    {
        
        for(int i=0;i<35;i++)
        {
            for(int j=0;j<1005;j++)
            {
                dp[i][j]=-1;
            }
        }
        return (int)dfs(d,f,tar);
    }
};
