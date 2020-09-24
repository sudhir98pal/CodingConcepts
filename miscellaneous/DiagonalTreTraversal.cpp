// Q link-> https://www.interviewbit.com/problems/diagonal-traversal/
 void sp( map<int,vector<int>> &mp,TreeNode* A,int l)
 {
     if(A==NULL) return;
     mp[l].push_back(A->val);
     sp(mp,A->left,l+1);
     sp(mp,A->right,l);
 }
vector<int> Solution::solve(TreeNode* A) 
{
    map<int,vector<int>> mp;
    sp(mp,A,0);
    
    vector<int> ans;
    for(auto x:mp)
    {
        for(auto y:x.second)
        {
            ans.push_back(y);
        }
        
    }
    return ans;
}
