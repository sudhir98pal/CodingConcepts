// Q link -> https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        if(n<=1) return n;
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                    }
                }
            }
        }
        
    return *max_element(dp,dp+n);
        
    }
};
