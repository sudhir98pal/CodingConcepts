class Solution {
public:
    
    int parent[10005];
    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    
    
    
    // Q link -> https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
    int removeStones(vector<vector<int>>& stones) 
    {
        int n=stones.size();
        int m=stones[0].size();
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        
        int ans=0;
        // making all possible edges between points
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                
                // checking if rows and column matches
                
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                {
                    
                  
                    int x=find(i);
                    int y=find(j);
                    if(x!=y)
                    {
                        parent[x]=y;
                    }
                }
            }
        }
        for(int i=0;i<n;i++) if(parent[i]==i) ans++;
        return n-ans;
    }
};
