// Q LINK->https://codeforces.com/contest/1447/problem/C
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
while(t-->0)
{
 
ll n,cap;
cin>>n;
cin>>cap;
vector<pair<ll,ll>> v;
ll x;
rep(i,n)
{
 
    cin>>x;
    v.push_back({x,i+1});
}
bool ans=true;
vector<ll> q;
ll half=cap/2;
if(cap%2) half++;
 
vector<pair<ll,ll>> u;
for(int i=0;i<n;i++)
{
 
    if(v[i].first>=half&&v[i].first<=cap)
    {
        cout<<"1"<<endl;
        cout<<i+1<<endl;
        ans=false;
        break;
    }
    else{
        if(v[i].first<=cap)
        {
 
            u.push_back({v[i].first,v[i].second});
        }
    }
 
}
if(!ans)
{
 
    continue;
}
 
 
if(u.size()<=0)
{
    cout<<"-1"<<endl;
    continue;
}
 
 
vsort(u);
 
ll w=0;
bool found=false;
for(auto x:u)
{
 
    if(x.first+w>=half&&x.first+w<=cap)
    {
 
        w=x.first+w;
        q.pb(x.second);
        found=true;
        break;
    }
    else{
 
        w=x.first+w;
        q.push_back(x.second);
 
    }
}
 
 
if(found)
{
    cout<<q.size()<<endl;
    out(q);
    cout<<endl;
 
}
else{
    cout<<"-1"<<endl;
}
 
}}
