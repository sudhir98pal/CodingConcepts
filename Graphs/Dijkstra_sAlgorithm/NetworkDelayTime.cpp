// Q Link->https://leetcode.com/problems/network-delay-time/
#define inf 10000

class edge
{
    public:
    int distination;
    int time;
};

struct compare
{
    bool operator()(const edge &a,const edge &b)
    {
        return a.time>=b.time;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        vector<vector<edge> >g(N+1);
        for(auto x:times)
        {
            edge e;
            e.distination=x[1];
            e.time=x[2];
            g[x[0]].push_back(e);
        }
          
        int vis[N+1];
        for(int i=0;i<=N;i++)
        {
            vis[i]=false;
        }
        int ans[N+1];
        for(int i=0;i<=N;i++)
        {
            ans[i]=inf;
        }
        ans[0]=0;
        ans[K]=0;
       
    priority_queue<edge, vector<edge>,compare>pq;
             
        edge source;
        source.distination=K;
        source.time=0;
        pq.push(source);
  
        while(pq.empty()==false)
        {
            edge e=pq.top();
     
            pq.pop();
            vis[e.distination]=true;
            ans[e.distination]=min(ans[e.distination],e.time);
            
            for(auto x:g[e.distination])
            {
                if(vis[x.distination]==false)
                {
                    edge temp;
                    temp.distination=x.distination;
                    temp.time=x.time+e.time;
                    pq.push(temp);
                }
            }
            
        }
   

        int p=*max_element(ans,ans+N+1);
           // finding max so that we get max upper bound of
                //time that any node need to receive signal;
  
        if(p>=inf) return -1;
        return p;
        
        
        
    }
};
