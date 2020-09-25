// Q link->https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    
    int maxProfit(vector<int>& prices) 
    {
        
        int n=prices.size();
        if(n<=1) return 0;
        int maxSell=0;
        int maxBuy=-10005;
        for(int i=0;i<n;i++)
        {
            int oldSell=maxSell;
            int oldBuy=maxBuy;
            maxBuy=max(maxBuy,oldSell-prices[i]) ;// Buying=> -Prices; 
            maxSell=max(maxSell,oldBuy+prices[i]);// Selling=> +prices;
        }
        
        return maxSell;
    
    }
};
