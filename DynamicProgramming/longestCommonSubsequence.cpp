class Solution1 {
public:
    int longestCommonSubsequence1(string s, string p)
    {
        int n=s.length();
        int m=p.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(s[i-1]==p[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }
                }
            }
        }
        
        return dp[n][m];
        
    }
};

// ----------OR--------------OR------------------------------OR-----------------------------------------------


class Solution2 {
public:
    int n,m;
    string a,b;
    
    int solve(vector<vector<int>> &dp,int i,int j )
    {
        if(i>=n||j>=m) return 0;
        if(a[i]==b[j])
        {
            if(dp[i][j]!=-1) return dp[i][j];
          else return dp[i][j]=1+solve(dp,i+1,j+1);
        }
        else
        {
            int x,y;
            if(dp[i][j+1]!=-1)
            {
                x=dp[i][j+1];
            }
            else
            {
                x=solve(dp,i,j+1);
            }
            if(dp[i+1][j]!=-1)
            {
                y=dp[i+1][j];
            }
            else
            {
                y=solve(dp,i+1,j);
            }
            
            return dp[i][j]=max(x,y);
        }
    }
    int longestCommonSubsequence2(string s, string p) 
    {
         n=s.length();
         m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        a=s;
        b=p;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(dp,0,0);
  
       
    }
};
