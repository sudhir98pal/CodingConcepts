// Q Link ->https://leetcode.com/problems/serialize-and-deserialize-binary-tree/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root==nullptr) return "S";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
       TreeNode* deserialize(string data) 
       {
              return deserialize2(data) ;
       }
    
    TreeNode* deserialize2(string &data) 
    {
        if(data[0]=='S')
        {
            if(data.size()>1) data=data.substr(2); // 2...endOfstring
                
                return nullptr;
            
        }
        else
        {
            
            int position=data.find(',');
            int val=stoi(data.substr(0,position));
            // val is from 0 to before ','
            // stoi converts string to number;
            data=data.substr(position+1) ;// afte ',' to end of string
                TreeNode * root=new TreeNode(val);
            root->left=deserialize2(data);
            root->right=deserialize2(data);
            return root;
        }
        
    }
    
        

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
