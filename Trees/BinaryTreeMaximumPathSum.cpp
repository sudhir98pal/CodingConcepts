// Q link->https://leetcode.com/problems/binary-tree-maximum-path-sum/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int dfs(TreeNode *root)
    {
        if(root==NULL) return 0;
        else
        {
            int l=dfs(root->left);
            int r=dfs(root->right);
            int x=max({l,r,l+r,0})+root->val;
            ans=max(ans,x);
            return max({0,l,r})+root->val;
            
        }
    }
    int maxPathSum(TreeNode* root)
    {
        ans=INT_MIN;
        dfs(root);
        return ans;
    }
};
