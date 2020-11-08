/*A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
*/
class Solution {
public:
    int minDeletions(string s) 
    {
    int count = 0;
 
    vector<int> dp('z' - 'a'+10, 0);

    for (char c: s) { ++dp[c - 'a']; }
    priority_queue<int> pq;
  
    for (int c: dp) 
    {
        if (c != 0)
        { 
            pq.push(c); 
        }
    }
    while (!pq.empty()) 
    {
        int most_frequent = pq.top();
        pq.pop();
        if (pq.empty())
        { 
            return count;
        }

        if (most_frequent == pq.top())
        {
            if (most_frequent > 1) {
                pq.push(most_frequent - 1);
            }
            count++;
        }

    }
    return count;
        
      
    }
};
