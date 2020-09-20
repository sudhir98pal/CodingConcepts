// Q link ->https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        if(n==0) return {};
        int m=matrix[0].size();
        int l=0;
        int r=m-1;
        int top=0;
        int down=n-1;
        vector<int> ans;
        int f=0 ;// 0-> left to right ,1->top to down 2->right to left 3 ->down to top
       
            while(l<=r&&top<=down)
            {
                
                if(f==0)
                {
                    for(int i=l;i<=r;i++)
                    {
                        ans.push_back(matrix[top][i]);
                    }
                    
               
                    top++;
                    
              f=1;
                    
                    
                    continue;
                }
                
                if(f==1)
                {
                    
                    for(int i=top;i<=down;i++)
                    {
                           ans.push_back(matrix[i][r]);
                    }
                    
                    r--;
              f=2;
                    continue;
                }
                
                if(f==2)
                {
                    
                    for(int i=r;i>=l;i--)
                    {
                        ans.push_back(matrix[down][i]);
                    }
                    down--;
                       
                    f=3;
                      continue;
                }
                 
                
                if(f==3)
                {
                           for(int i=down;i>=top;i--)
                    {
                        ans.push_back(matrix[i][l]);
                    }
                    l++;
                       f=0;
                    continue;
                }
            }
            
        return ans;
    }
};
