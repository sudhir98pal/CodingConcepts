// Q Link->https://leetcode.com/problems/letter-case-permutation/
class Solution {
public:
    vector<string> ans;
    string s;
    void dfs(int j)
    {
       
        ans.push_back(s);
        for(int i=j;i<s.length();i++)
        {
             if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=toupper(s[i]);
            dfs(i+1);
            s[i]=tolower(s[i]);
        }
    
         if(s[i]>='A'&&s[i]<='Z')
        {
             s[i]=tolower(s[i]);
          
            dfs(i+1);
              s[i]=toupper(s[i]);
        }
            
        }
       
    }
    vector<string> letterCasePermutation(string S) 
    {
        s=S;
        ans.clear();
        dfs(0);
        return ans;
    }
};
