// Q link ->https://leetcode.com/problems/knight-probability-in-chessboard/
/*

On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. 
The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
A chess knight has 8 possible moves it can make. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

*/
class Solution {
public:
    int n;
      
    double a[30][30][101];
    bool issafe(int x,int y)
    {
        if(x<0||x>=n||y<0||y>=n) return false;
        return true;
    }
    double dfs(int x,int y,int k)
    {
        
        if(issafe(x,y)==false) return 0.0;
        if(k==0) a[x][y][k]=1.00;
       
        
        if(a[x][y][k]!=-1.0)
        {
            return a[x][y][k];
        }
       
    double ans=0.0;
        int dx[]={-2,-1,1,2,2,1,-1,-2};
        int dy[]={1,2,2,1,-1,-2,-2,-1};
        for(int p=0;p<=7;p++)
        {
            int nx=x+dx[p];
            int ny=y+dy[p];
            ans+=dfs(nx,ny,k-1);
                   
                
            
        }
        
        return a[x][y][k]=(double)ans/8;
        
        
        
    }
    double knightProbability(int N, int K, int r, int c)
    {
        if(K==0)
        {
            return 1.00;
        }
        n=N;

          a[r][c][K]=1.0;
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<30;j++)
            {
                
                for(int k=0;k<101;k++)
                {
                    a[i][j][k]=-1.0;
                }
                
            }
        }
      
       return dfs(r,c,K);
      
       
        
    }
};
