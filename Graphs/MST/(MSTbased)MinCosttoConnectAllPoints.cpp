// Q link->https://leetcode.com/problems/min-cost-to-connect-all-points/

#define ll long long int 

class Solution {
public:
    
    
   
    ll parent[1005];
    // as max number of pints are 1000
    
     ll find(ll x)
    {
         if(parent[x]==x) return x;
         return parent[x]=find(parent[x]);
        
    }
    
    bool merge(ll x,ll y)
    {
        ll f=find(x);
        ll s=find(y);
        if(f==s) return false;
        
        parent[f]=s;
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        ll n=points.size();
        ll e=n*(n-1)/2;
        // number of edges is nc2
        ll requirededges=n-1;
        // there are n-1 edges in mst
        vector<pair<ll,pair<ll,ll>> >edges;
        // {weight ,{x,y}}
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        
        // forming edges
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll weight=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({weight,{i,j}});
            }
        }
        
        
        // sorting 
        sort(edges.begin(),edges.end());
        ll ans=0;
        
        for(auto x:edges)
        {
            if(merge(x.second.first,x.second.second))// no cycle take this egdes
            {
                ans+=x.first;
                    requirededges--;
                  if(requirededges==0) break;
            }
          
            
            
        }
        
        return ans;
        
        
    }
};
