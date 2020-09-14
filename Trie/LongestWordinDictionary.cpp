// Q Link https://leetcode.com/problems/longest-word-in-dictionary/
/*
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"

*/

class TrieNode
{
    public:
    bool isWord;
    TrieNode *children[26];
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isWord=false;
    }
    
};


class Solution {
    
    private:
    TrieNode * root=new TrieNode();
    
public:
    bool isPresent(string s)
    {
        TrieNode *current=root;
        char last=s.back();
        
        s.pop_back();// as to check abc is present for abcd.
        
        for(auto x:s)
        {
            if(!current->children[x-'a']) return false;
            current=current->children[x-'a'];
            
        }
        
        
        // case :-> when string is of size one. add it to Trie and return true;
        if(s.empty())
        {
            current->children[last-'a']=new TrieNode();
            current->children[last-'a']->isWord=true;
            return true;
            
        }
        
        
        // if not 
        return  current->isWord;
        
    }
    
    
    void addStringToTrie(string s)
    {
        TrieNode *current=root;
        for(auto x:s)
        {
            
            if(!current->children[x-'a'])
            {
                current->children[x-'a']=new TrieNode();
            }
            
            current=current->children[x-'a'];
        }
        
        current->isWord=true;
        
        
    }
    
    
    string longestWord(vector<string>& v)
    {
       sort(v.begin(),v.end());
        
        string ans=v[0];
        
        for(int i=0;i<v.size();i++)
        {
            if(isPresent(v[i]))
            {
                if(ans.size()<v[i].size())
                {
                    ans=v[i];
                }
                
                addStringToTrie(v[i]);
            }
        }
        
        
        return ans;
    }
};
