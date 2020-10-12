// Q link->https://leetcode.com/problems/snakes-and-ladders/



class Solution 
{
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n=board.size();
        int newBoard[n*n+1];
        bool vis[n*n+1];
        for(int i=0;i<=n*n;i++)
        {
            vis[i]=false;
        }
         //  +1 to start process from 1 insted from 0;
        bool reverseRow=false;
        int k=1;
  
        for(int i=n-1;i>=0;i--)
        {
            if(reverseRow)
            {
                for(int j=n-1;j>=0;j--)
                {
                    newBoard[k]=board[i][j];
                    k++;
                }
                reverseRow=false;
            
            }
            else
            {
            for(int j=0;j<n;j++)
            {
                newBoard[k]=board[i][j];
                    k++;
            }
                reverseRow=true;
            }
         
        }
       
        queue<pair<int,int>> q;
        
        q.push({1,0});
        
while(!q.empty())
{
 
    
        auto p=q.front();
        
          q.pop();

        if(p.first==n*n) return p.second;
       
        for(int i=p.first+1;i<=min(n*n,p.first+6);i++) // trying all 6 faces of dice
        {
         
         
    if(vis[i]==false)
    {
        
    vis[i]=true;
            
             if(newBoard[i]!=-1)
        {
            q.push({newBoard[i],p.second+1});
        }
        else
        {
            q.push({i,p.second+1});
        }
            
            
        }
            
        }
       
        
        
    
 
 
    
    
}
        
    return -1;   
        
        
        
        
        
        
        
        
    }
};
