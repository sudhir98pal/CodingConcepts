
// Q LINK->https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n=s.size();
        int m=p.size();
        
        if(n==0)
        {
            if(m==0) return 1;
            return p[0]=='*'&&m==1;
        }
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=false;
            }
        }
        
        dp[0][0]=1;
        // empty character can be matched with empty string;
        
        // Only '*' can match with empty string 
        for(int j=1;j<=m;j++)
        {
            if(p[j-1]=='*')
            {
                dp[0][j]=dp[0][j-1];
            }
        }
        
        
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]=='*')
                {
                    // *=s[i]||*=''
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
                }
                else
                {
                    
                    
                    if(p[j-1]=='?'||s[i-1]==p[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        return dp[n][m];
        
        
    }
};
