// Q Link->https://leetcode.com/problems/unique-paths-iii/
class Solution {
public:
    int vis[21][21];
    int c;
    int dfs(int i,int j,vector<vector<int>> &g,int val)
    {   int n=g.size();
        int m=g[0].size();
     if(i<0||j<0||i>=n||j>=m||vis[i][j]||g[i][j]==-1) return 0;
     if(g[i][j]==2)
     {// means all empty squares that can be walk over is covered and finally reach to distination.
         if(c==val) return 1;
         else return 0;
     }
     vis[i][j]=1;
     int ans=0;
     int dx[]={-1,0,1,0};
     int dy[]={0,1,0,-1};
     for(int p=0;p<4;p++)
     {
         int nx=dx[p]+i;
         int ny=dy[p]+j;
         ans=ans+dfs(nx,ny,g,val+1);
     }
     vis[i][j]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& g)
    { c=0;
        int n=g.size();
        int m=g[0].size();
        int sx,sy;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==1)
                {
                    sx=i;
                    sy=j;
                }
                
                if(g[i][j]==0)
                {
                    c++;
                }
            }
        }
     
     return dfs(sx,sy,g,-1);
    }
};
