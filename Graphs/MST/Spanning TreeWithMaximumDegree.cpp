/*
Q Link:->https://codeforces.com/problemset/problem/1133/F1

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
#define mm 200043
#define put(c) cout<<c<<endl;
#define ulta(a) reverse(a.begin(),a.end())
#define out(a) for(auto x:a) cout<<x<<" ";
#define sp(arr) sort(arr,arr+sizeof(arr)/sizeof(arr[0]));
#define bolt ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<int> g[mm];
int deg[mm];
bool vis[mm];
vector<pair<int,int>> ans;

void bfs(int r)
{
    queue<int> q;
    q.push(r);
 vis[r]=true;
    while(!q.empty())
    {
        int p=q.front();

        q.pop();


        for(auto x:g[p])
        {

            if(vis[x]) continue;
            ans.pb({p,x});
               vis[x]=true;
            q.push(x);
        }

    }


}
int main()
{
    bolt
int n;
cin>>n;
int m;
cin>>m;
rep(i,n)
{
    vis[i]=false;
    deg[i]=0;
}
rep(i,m)
{
   int x;
   int y;
   cin>>x;
   cin>>y;
   x--;
   y--;
   g[y].pb(x);
   g[x].pb(y);
   deg[x]++;
   deg[y]++;

}
int node=0;
int maxDegree=0;
for(int i=0;i<n;i++)
{

    if(deg[i]>=maxDegree)
    {
        maxDegree=deg[i];
        node=i;
    }
}

bfs(node);
for(auto x:ans)
{
    cout<<x.first+1<<" "<<x.second+1<<endl;
}
return 0;
}
