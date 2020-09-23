// Q link -> https://leetcode.com/problems/01-matrix/
// TRICK -> START FROM 0 IN BFS

class Solution {
public:
  
 
   
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) 
    {
        int n=a.size();
        if(n==0) return {};
        int m=a[0].size();
     int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                 
                    a[i][j]=n+m;
                }
            }
        }
        int nx,ny;
        while(!q.empty())
        {
            int c=q.size();
            while(c-->0)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    nx=p.first+dx[i];
                    ny=p.second+dy[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m)
                    {
                      if(a[nx][ny]==m+n)  q.push({nx,ny});
                        
                        a[nx][ny]=min(a[nx][ny],a[p.first][p.second]+1);
                    }
                }
            }
        }
        
        
        return a;
    }
};
