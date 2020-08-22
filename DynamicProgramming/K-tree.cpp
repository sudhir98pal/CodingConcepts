
// Q->:https://codeforces.com/problemset/problem/431/C

#include<bits/stdc++.h>
#define bolt ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int n,k,d;
int dp[105][2];
int  dfs(int sum,bool is_valid_path)
{


if(sum>n) return 0;


if(sum==n)
{

    if(is_valid_path)
    {
        return 1;
    }
    else return 0;
}

if(dp[sum][is_valid_path]!=-1)
{
    return dp[sum][is_valid_path];
}

int ans=0;
for(int i=1;i<=k;i++)
{
    ans=(ans+dfs(sum+i,(is_valid_path||(i>=d))))%mod;
    // already is_valid or now become valid both are ok
}

return dp[sum][is_valid_path]=ans%mod;

}
int main()
{
    bolt

cin>>n;
cin>>k;
cin>>d;

for(int i=0;i<105;i++)
{

    for(int j=0;j<2;j++)
    {

        dp[i][j]=-1;
    }
}
cout<<dfs(0,0)<<endl;





}



