// Q Link->https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) 
    {
        int n=a.size();
        if(n==0) return 0;
        int m=a[0].size();
       long long int dp[n][m];
        
        // if at finish there is obstacle than it cannot reach anyhow to finish
        if(a[n-1][m-1]) return 0;
        
        // if at start there is obstacle than it cannot reach anyhow to finish
        if(a[0][0]) return 0;
        
        dp[0][0]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i][0])
            {
                dp[i][0]=0;
            }
            else
            {
                dp[i][0]=dp[i-1][0];
            }
        }
        
          for(int i=1;i<m;i++)
        {
            if(a[0][i])
            {
                dp[0][i]=0;
            }
            else
            {
                dp[0][i]=dp[0][i-1];
            }
        }
        
        for(int i=1;i<n;i++)
        {
            
            for(int j=1;j<m;j++)
            {
                if(a[i][j])
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
            
        }
        
        return (int)dp[n-1][m-1];
        
    }
};
