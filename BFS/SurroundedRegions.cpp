/*
Q link->https://leetcode.com/problems/surrounded-regions/

NOTE : THE QUESTION IS ALL ABOUT FIRST PROCESS ALL BORDER ELEMENT AS 'O' TO 'S'AND 
THEN DO BFS TO CONNECTED ELEMENTS
AFTER THIS REPLACE ALL S TO O AND REST WITH X



*/


class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        
        
        int n=board.size();
        if(n==0) return;
        int m=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                       if(i==n-1||j==m-1||i==0||j==0)
                       {
                            q.push({i,j});
                           board[i][j]='S';
                       }
                   
                    
                }
            }
        }
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
        int nx,ny,x,y;
        
    while(!q.empty())
    {
        int c=q.size();
        while(c-->0)
        {
            pair<int,int> p=q.front();
            q.pop();
         
            x=p.first;
            y=p.second;
           
            
            for(int i=0;i<4;i++)
            {
                nx=p.first+dx[i];
                ny=p.second+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m)
                {
                    if(board[nx][ny]=='O')
                    {
                       q.push({nx,ny});
                        board[nx][ny]='S';
                    }
                  
                }
                       
               
            }
         
        
                
           
        }
    }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j]=='S'?board[i][j]='O':board[i][j]='X';
            }
        }
        
        
        
        
    }
};
