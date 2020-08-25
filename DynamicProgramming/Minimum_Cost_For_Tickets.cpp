
// Q Link https://leetcode.com/problems/minimum-cost-for-tickets/

#include<bits/stdc++.h>

using namespace std;
class sudhir
{
public:
    set<int> s;
    int singleDayCost;
    int weeklyCost;
    int monthlyCost;
    int dp[366];
    int dfs(int day)
    {
        if(day>365) return 0;
        if(dp[day]!=-1) return dp[day];

        if(s.find(day)!=s.end())
        {

            return dp[day]=min(dfs(day+1)+singleDayCost,min(dfs(day+7)+weeklyCost,dfs(day+30)+monthlyCost));
        }
        else
        {
            return dp[day]=dfs(day+1);
        }
    }

    int mincostTickets(vector<int>& days, vector<int>& costs)
    {

        for(auto x:days)
        {
            s.insert(x);
        }

        for(int i=0;i<366;i++) dp[i]=-1;

        singleDayCost=costs[0];
        weeklyCost=costs[1];
        monthlyCost=costs[2];
        return dfs(0);


    }
};

int main()
{
sudhir pal;
vector<int> days={1,2,3,4,5,6,7,8,9,10,30,31};
vector<int> costs={2,7,15};
int cost=pal.mincostTickets(days,costs);
cout<<cost<<endl;


return 0;
}
