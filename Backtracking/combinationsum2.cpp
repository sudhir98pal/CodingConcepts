// Q->link: https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    set<vector<int> > ans; 

    void solve(vector<int>&v,int target,int sum,vector<int> &candidates,int i)
    {
        
        if(sum>target) return;
 
        if(sum==target)
        {
           
        vector<int> vv=v;
            sort(vv.begin(),vv.end());
            ans.insert(vv);
            return;
        }
          
        
        for(int j=i;j<candidates.size();j++)
        {
            int x=candidates[j];
            v.push_back(x);
          if(sum+x<=target)  solve(v,target,sum+x,candidates,j+1);
             v.pop_back();  
                
        }
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        
        vector<vector<int>> ans2;
        vector<int> v;
        
        solve(v,target,0,candidates,0);
        for(auto x:ans)
        {
            ans2.push_back(x);
        }
        
        return ans2;
        
    }
};
