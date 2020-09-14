// Q Link->https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(vector<vector<char>> &g,int i,int j)
    {
        int n=g.size();
        int m=g[0].size();
        if(i<0||j<0||i>=n||j>=m||g[i][j]=='0') return ;
        g[i][j]='0';
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            dfs(g,nx,ny);
        }
    }
    int numIslands(vector<vector<char>>& g)
    {
        int ans=0;
      
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j]=='1')
                {    
                    ans++;
                    dfs(g,i,j);
                }
            }
        }
        
        return ans;
    }
};
