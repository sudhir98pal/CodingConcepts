// Q link ->https://leetcode.com/problems/word-search-ii/
class TrieNode
{
    public:
    TrieNode * children[26];
    bool isWord;
    TrieNode ()
    {
        isWord=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};


class Solution
{
    
public:
    int n,m;
    int vis[1000][1000];
    unordered_set<string> ans;
    TrieNode * root;
    bool isPresent(string word)
    {
        TrieNode * temp=root;
        for(auto x:word)
        {
            if(temp->children[x-'a']==NULL)
            {
                return false;
            }
            temp=temp->children[x-'a'];
        }
        
        return temp->isWord;
        
    }
    
    void insert(string word)
    {
           TrieNode * temp=root;
        for(auto x:word)
        {
            if(temp->children[x-'a']==NULL)
            {
                temp->children[x-'a']=new TrieNode();
            }
            temp=temp->children[x-'a'];
        }
        
         temp->isWord=true;
    }
    void dfs(vector<vector<char>>& board,int x,int y,string s,TrieNode * mroot)
    {
   
        if(x<0||x>=n||y<0||y>=m) return ;
        if(mroot->children[board[x][y]-'a']==NULL) return;
        if(vis[x][y]==1) return;
  
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
         s+=board[x][y];
              mroot=mroot->children[board[x][y]-'a'];
        if(mroot->isWord)
        {
                
            ans.insert(s);
            
           // return ; Warning donnot return here as aaa found aaaa to be found can be
        }
       
        vis[x][y]=1;
  
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            dfs(board,nx,ny,s,mroot);
        }
        s.pop_back();
        vis[x][y]=0;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        
         n=board.size();
        if(n==0) return {};
         m=board[0].size();
        root=new TrieNode();
        for(auto x:words)
        {
            insert(x);
        }
     
      
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                string s="";
                    TrieNode * mroot=root;
                dfs(board,i,j,s,mroot);
            }
        }
        
        vector<string> v(ans.begin(),ans.end());
        return v;
    }
};
