//Q link -> https://leetcode.com/problems/redundant-connection/
class Solution {
public:
    int parent[1005];
    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    
    bool merge(int x,int y)
    {
        int xx=find(x);
        int yy=find(y);
        if(xx==yy) return true;// forms cycle thus it can removed
        
        parent[xx]=yy;
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        for(int i=0;i<1005;i++)
        {
            parent[i]=i;
        }
        
        
        int a;
        int b;
        
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            if(merge(u,v))
            {
                a=u;
                b=v;
            }
        }
        
        
        return {a,b};
    }
};
