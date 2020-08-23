// Q link :->https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        
        int ans=0;
        int n=rooms.size();
        if(n<=1) return 1;
        
        bool vis[n];
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
        }
        
        
        vis[0]=1;
        queue<int> q;
        for(auto x:rooms[0])
        {
            q.push(x);
        }
        ans++;
        if(q.size()==0) return false;
        while(!q.empty())
        {
            int c=q.size();
            while(c-->0)
            {
                
                
                int p=q.front();
                q.pop();
                if(vis[p]) continue;
                vis[p]=1;
                ans++;
                for(auto i:rooms[p])
                {
                    if(vis[i]==false)
                    {
                        q.push(i);
                    }
                }
                
                
            }
        }
    
        
        
        
        return ans>=n;
    }
};
