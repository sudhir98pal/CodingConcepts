//https://leetcode.com/problems/group-anagrams/
// o(m*n) time and space


class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {        vector<vector<string>> ans;
        int n=strs.size();
     if(n<=1)
     {
         ans.push_back(strs);
         return ans;
     }
unordered_map<string,vector<string>> mp;
        char c;
        string temp;
        for(string x:strs)
        {
          vector<int> freq(26,0);
            for(char y:x)
            {
                freq[y-'a']++;
            }
            
            temp="#";
           
            for(int i=0;i<26;i++)
            {
                if(freq[i]>0)
                {
                    char c=i+'a';
                    temp+=c;
                    temp+=(freq[i]+'a');
                }
            }
            if(temp.size()>0)
            {
                mp[temp].push_back(x);
            }
        }

        
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        
        return ans;
    
        
    }
};
