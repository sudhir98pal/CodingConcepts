class Solution {
public:
    int countSubstrings(string s)
    {
        int ans=0;
        int n=s.size();
        if(n==0) return 0;
        int dp[n][n];
        
    memset(dp,false,sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
            ans++;
        }
        
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
            {
                dp[i][i-1]=true;
                // if dp[i-1][i]=true then u have to swap i and j for len>=2
                ans++;
            }
        }
        
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[i-1][j+1]&&s[i]==s[j])
                {
                    ans++;
                    dp[i][j]=true;
                }
            }
        }
        
        return ans;
    }
};
