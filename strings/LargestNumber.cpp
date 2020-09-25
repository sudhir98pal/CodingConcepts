// Q link ->https://leetcode.com/problems/largest-number/
class Solution {
public:
    

   
    string largestNumber(vector<int>& nums) 
    {
        vector<string> v;
        int c=0;
        for(auto x:nums)
        {
            c+=(x==0);
            v.push_back(to_string(x));
        }
        if(c>=nums.size()) return "0";
  
        
        sort(v.begin(),v.end(),[](const string &a,const string &b)->bool
             {
                 
               
               
              return a+b>=b+a;
             
                 
             });
        
        string ans="";
        for(auto x:v)
        {
            ans+=x;
        }
            
        return ans;
       
    }
};
