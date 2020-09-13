//Q->link :https://leetcode.com/problems/combination-sum-iii
class Solution {
public:
    vector<vector<int>> v;
    int k;
    int n;
    void solve(vector<int> s,int sum)
     { 
   
        if(s.size()>k) return;
        if(sum>n) return;
        if(s.size()==k&&sum==n)
        {

           
            v.push_back(s);
            return ;
        }
        
    int start=s.empty()?1:s.back()+1;
        for(int i=start;i<=9;i++)
        {
                    
            if(sum+i<=n)
            {  
       
                
                s.push_back(i);
                solve(s,sum+i);
                s.pop_back();
                
              
            }
           
                
                
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
              
        if(k>n) return {};
        this->k=k;
        this->n=n;
        vector<int> s;
        solve(s,0);
  
        
    
        return v;
    }
};
