// Q link-> https://leetcode.com/problems/count-binary-substrings/
class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        
        int n=s.length();
        if(n==0) return 0;
        int group[n];
        group[0]=1;
        int t=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                t++;
                group[t]=1;
            }
            else
            {
                group[t]++;
            }
        }
        
    int ans=0;
        for(int i=1;i<=t;i++)
        {
            ans+=min(group[i-1],group[i]);
        }
        
        return ans;
      
    }
};
