// Q Link->https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int dp[amount+1];
        int n=coins.size();
        for(int i=0;i<=amount;i++)
        {
          dp[i]=amount+1;  
        }
        
        dp[0]=0;
        // if amount =0 then coin require is zero;
        
        for(int i=1;i<=amount;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                {
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
                
            }
            
        }
        if(dp[amount]>amount) return -1;
        return dp[amount];
        
    }
};
