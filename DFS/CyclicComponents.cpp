/*
Q link ->https://codeforces.com/problemset/problem/977/E

Let's solve this problem for each connected component of the given graph separately.

It is easy to see that the connected component is a cycle iff the degree of each its vertex equals to 2.

So the solution is to count the number of components such that every vertex in the component has degree 2.

The connected components of the graph can be easily found by simple dfs

*/


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
const int mm=200005;
vector<int> g[mm];
int degree[mm];
bool vis[mm];

int n,m;

int ans;
void dfs(int x,vector<int> &v)
{
    if(vis[x]) return;
    vis[x]=true;
    v.pb(x);
    for(int i:g[x])
    {

        dfs(i,v);
    }

}

bool solve(vector<int> &v)
{


    for(auto x:v)
    {

        if(degree[x]!=2) return false;
    }
    return true;
}

int main()
{

    bolt

cin>>n;
cin>>m;
int u,v;
rep(i,m)
{
    cin>>u;
    cin>>v;
    g[u].pb(v);
    g[v].pb(u);
    degree[u]++;
    degree[v]++;

}

for(int i=1;i<=n;i++)
{
    vis[i]=false;
}

ans=0;
for(int i=1;i<=n;i++)
{
    if(!vis[i])
    {
        vector<int> v;
        dfs(i,v);

        if(solve(v))
        {

            ans++;


        }

    }

}

cout<<ans<<endl;


}

