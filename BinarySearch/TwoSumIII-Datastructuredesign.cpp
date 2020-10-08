/*Design a data structure that accepts integers of a stream, and checks if it has a pair of integers that sum up to a particular value. 

Implement a TwoSum class:

TwoSum() Initializes the TwoSum object, with an empty array initially.
void add(int number) Adds number to the data structure.
boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.
*/
class TwoSum {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    TwoSum() 
    {
        v.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) 
    {
        if(v.size()==0)
        {
            v.push_back(number);
            return;
        }
        v.insert(lower_bound(v.begin(),v.end(),number),number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        int l=0;
        int r=v.size()-1;
        if(r==0) return false;
        while(l<r)
        {
            if(v[l]+v[r]==value) return true;
            if(v[l]+v[r]>value) r--;
            else
            {
                l++;
            }
        }
        return false;
    }
};
