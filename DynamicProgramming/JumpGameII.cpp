/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

*/
const long int mm=INT_MAX-10;
    
class Solution {
public:
    
    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long int> dp(n,mm);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=min(n-1,i+nums[i]);j++)
            {
                
                dp[j]=min(dp[j],1l*(1+dp[i]));
            }
        }
        
        
        return (int)dp[n-1];
    }
};
