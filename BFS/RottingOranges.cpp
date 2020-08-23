// Q link :-> https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int n,m;
    bool isSafe(int x,int y)
    {
        if(x<0||x>=n||y<0|y>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
         n=grid.size();
        if(n==0) return 0;
         m=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        

        if(fresh==0) return 0;
        int ans=0;
        
        
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty())
        {
            if(fresh<=0)
            {
                break;
            }
            ans++;
            int c=q.size();
            while(c-->0)
            {
                   auto p=q.front();
            q.pop();
    
            for(int i=0;i<4;i++)
            {
                int nx=p.first+dx[i];
                int ny=p.second+dy[i];
                if(isSafe(nx,ny))
                {
                    if(grid[nx][ny]==1)
                    {
                        fresh--;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            if(fresh<=0)
            {
                break;
            }
                
            }
         
        }
        
        
        
        
        
        
        
        
        
        if(fresh>0) return -1;
        return ans;
        
    }
};
