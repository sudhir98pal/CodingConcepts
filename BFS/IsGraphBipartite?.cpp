// Q link:->  https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& g)
    {
                int n=g.size();
        if(n<=0) return 1;
         int color[n+1];
        for(int i=0;i<=n;i++)
        {
            color[i]=2;
        }
        
        for(auto x:g)
        {
            for(auto u:x)
            {
                if(color[u]==2)
                {
                               queue<pair<int,int>> q;
                      q.push({u,1});
                 color[u]=1;
        
        while(!q.empty())
        {
            int c=q.size();
            while(c-->0)
            {
                
                auto p=q.front();
                q.pop();
                
                for(auto x:g[p.first])
                {
                    if(color[x]==2)
                    {
                        color[x]=1-p.second;
                        q.push({x,1-p.second});
                    }
                    else
                    {
                        if(color[x]==p.second) return false;
                    }
                    
                }
            }
            
            
            
        }
              
                }
       
            }
        }
  

       
       
        return true;
        
    }
};
