// Q link->https://codeforces.com/contest/1454/problem/D

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
 
 
 
int main()
{
     bolt
int t;
cin>>t;
ll n;
while(t-->0)
{
 
map<ll,ll> mp;
cin>>n;
ll p=n;
while(n%2==0)
{
 
    mp[2]++;
    n>>=1;
}
 
 
for(ll i=3;i<=sqrt(n);i=i+2)
{
    while(n%i==0)
    {
 
        mp[i]++;
        n=n/i;
    }
}
 
if(n>2)
{
 
    mp[n]++;
}
 
 
ll ans=0;
ll num=0;
for(auto x:mp)
{
 
    if(x.second>ans)
    {
 
        ans=x.second;
        num=x.first;
    }
}
 
 
cout<<ans<<endl;
 
rep(i,ans-1)
{
 
    cout<<num<<" ";
    p=p/num;
}
 
 
cout<<p<<endl;
 
 
}
 
 
 
 
 
 
 
 
}
