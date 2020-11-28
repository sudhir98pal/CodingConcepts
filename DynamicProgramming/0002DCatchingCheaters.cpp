// Q link->https://codeforces.com/contest/1447/problem/D


#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define ld long double
#define vsort(v) sort(v.begin(),v.end())
#define vrsort(v) sort(v.begin(),v.end(),greater<int>())
#define mset(a,p) memset(a,p,sizeof(a))
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pi 3.141592653589793238
#define mode 1000000007
#define put(c) cout<<c<<endl
#define ulta(a) reverse(a.begin(),a.end())
#define out(a) for(auto x:a) cout<<x<<" ";
#define sp(arr) sort(arr,arr+sizeof(arr)/sizeof(arr[0]));
#define bolt ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;



ll lcs(string a,string b)
{
    ll n=a.size();
    ll m=b.size();
    ll dp[n+1][m+1];
    mset(dp,0);
ll ans=0;

    for(ll i=1;i<=n;i++)
    {

        for(ll j=1;j<=m;j++)
        {


            if(a[i-1]==b[j-1])
                {
                        // 4*lcs-|a|-|b|
                    // when a[i-1]==b[j-1] the 4*1-1-1=2
                   // dp[i][j]=1+dp[i-1][j-1];
                   //thus
                   dp[i][j]=max(dp[i][j],2+dp[i-1][j-1]);
                }
                else{

                    dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1])-1);
                    // -1 comes from 4*lcs is same but |a+1| or |b+1|
                    // occurs
                    // thus 4*lcs-(a+1)-b or 4*lcs-(a)-(b+1)
                }



            ans=max(ans,dp[i][j]);
        }
    }

    return ans;


}





int main()
{
     bolt

ll n,m;
cin>>n;
cin>>m;
string a,b;
cin>>a;
cin>>b;



cout<<lcs(a,b)<<endl;







}
