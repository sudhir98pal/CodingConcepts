// Q Link:-> https://leetcode.com/problems/design-add-and-search-words-data-structure/
class TrieNode
{
    public:
    TrieNode * children[26];
    bool isWord;
    TrieNode()
    {
        isWord=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        
    }
};


class WordDictionary {
    

    
    
    
public:
    /** Initialize your data structure here. */
    TrieNode * root;
    WordDictionary() 
    {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode * currentNode=root;
        for(char x:word)
        {
            if(!currentNode->children[x-'a'])
            {
                currentNode->children[x-'a']=new TrieNode;
            }
            currentNode=currentNode->children[x-'a'];
        }
        
        currentNode->isWord=true;
        
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return searchUtil(word,root);
    }
    
    private:
    
    bool searchUtil(string s,TrieNode * currentNode)
    {
        for(int i=0;i<s.size();i++)
        {
            char x=s[i];
            if(x!='.')
            {
                if(!currentNode->children[x-'a']) return false;
                currentNode=currentNode->children[x-'a'];
                
            }
            else
            {
                
                for(int j=0;j<26;j++)
                {
                    if(currentNode->children[j]&&searchUtil(s.substr(i+1),currentNode->children[j]))
                        return true;
                }
                
                return false;
                
                
            }
        }
        
        return currentNode->isWord;
    }
};

