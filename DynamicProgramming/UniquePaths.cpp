// Q link-> https://leetcode.com/problems/unique-paths/



class Solution {
public:
    int uniquePaths(int m, int n)
    {
        
      long long int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return (int)dp[n-1][m-1];
    }
};
