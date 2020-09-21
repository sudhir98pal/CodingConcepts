// Q link ->https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int tortoise=nums[0];
        int  hare=nums[0];
        while(true)
        {
            hare=nums[nums[hare]];
            tortoise=nums[tortoise];
            if(hare==tortoise) break;
        }
        
        
        hare=nums[0];
        while(tortoise!=hare)
        {
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        
        return hare;
    }
};
