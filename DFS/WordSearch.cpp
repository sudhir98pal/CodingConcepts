// Q link->https://leetcode.com/problems/word-search/
class Solution {
public:
    int vis[205][205];
    bool dfs(vector<vector<char>>& board, string word,int x,int y,int i)
    {
      
        int n=board.size();
        int m=board[0].size();
          
        if(x<0||y<0||x>=n||y>=m||vis[x][y]==1)
        {
            return  0;
        }
        
          if(i==word.size()) return 1;
     
        if(word[i]!=board[x][y]) return 0;
     
        vis[x][y]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
   
        for(int j=0;j<4;j++)
        {
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(i==word.size()-1&& word[i]==board[x][y]) return true;
           if(dfs(board,word,nx,ny,i+1)) return true;
        }
        
        vis[x][y]=0;
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word)
    {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                   if(dfs(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};
