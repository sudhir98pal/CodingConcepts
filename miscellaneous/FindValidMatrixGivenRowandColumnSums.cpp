// Q Link->https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c)
    {
        int n=r.size();
        int m=c.size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int i=0;
        int j=0;
        while(i<n&&j<m)
        {
            int x=min(r[i],c[j]);
            ans[i][j]=x;
            r[i]-=x;
            c[j]-=x;
            if(r[i]==0) i++;
            if(c[j]==0) j++;
            if(i>=n||j>=m) break;
            
        }
        
        return ans;
        
        
    }
};
