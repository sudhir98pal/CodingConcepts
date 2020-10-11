/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        
        int n=nums.size();
        if(n==0)
        {
            return {-1,-1};
        }
        int l1=-1;
        int r1=-1;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            
            
            int m=l+(r-l)/2;
            if(nums[m]==target)
            {
                l1=m;
                r=m-1;
            }
            else
            {
                
                
                if(nums[m]>target)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
           
        }
        
        if(l1==-1) return {-1,-1};
        l=0;
        r=n-1;
           while(l<r)
        {
            
            
            int m=l+(r-l)/2;
            if(nums[m]==target)
            {
                r1=m;
                l=m+1;
            }
            else
            {
                
                
                if(nums[m]>target)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
           
        }
        
        if(r1==-1) return {-1,-1};
        
        
        return {l1,r1};
        
        
    }
};
