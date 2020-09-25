// Q link-> https://leetcode.com/problems/sort-the-matrix-diagonally/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        
        int n=mat.size();
        if(n==0) return {};
        int m=mat[0].size();
        int i=n-1;
        int j=0;
        while(j<m)
        {
            int x,y;
            
            vector<int> v;
            for(x=i,y=j;x<n&&y<m;x++,y++)
            {
                
                v.push_back(mat[x][y]);
                
            }
            
            sort(v.begin(),v.end());
            int p=0;
             for(x=i,y=j;x<n&&y<m;x++,y++)
            {
                
                mat[x][y]=v[p++];
                 
                
            }
            
            
            
            
            if(i>0) i--;
            else j++;
            
        }
        
        
        
        
        
        
        
        
        
        return mat;
    }
};
