//Q LInk :->https://leetcode.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& a)
    {
       int n=a.size();
          if(n==0) return 0;
        int m=a[0].size();
      
        int maxLength=0;
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=(a[i][j]=='1');
                }
                else
                {
                   if(a[i][j]=='1')
                   {
                       dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                           
                           
                    }
                    else dp[i][j]=a[i][j]-'0';
                }
                
                maxLength=max(maxLength,dp[i][j]);
            }
        }
        
        return (int)maxLength*maxLength;
        
    }
};
