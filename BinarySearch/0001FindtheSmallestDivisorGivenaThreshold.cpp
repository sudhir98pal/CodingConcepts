// Q link ->https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int l=1;
        int n=nums.size();
        int r=nums[n-1];
        while(l<=r)
        {
            
            int m=l+(r-l)/2;
            
            
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum=sum+(nums[i]/m)+(nums[i]%m==0?0:1);
            }
          
            
            if(sum>threshold)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        
        return l;
        
        
        
    }
};
