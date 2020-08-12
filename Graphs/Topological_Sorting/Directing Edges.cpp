//Q->LINK : https://codeforces.com/contest/1385/problem/E

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
const int mm=2e5+5;
vector<int> g[mm];
int n,m;
int uu[mm],vv[mm];
vector<int> order;  // stores topological order of nodes
int pos[mm];// stores the position of nodes in topological sort
int con[mm];// 1=directed 0=undirected

bool topologicalsort()
{

order.clear();
vector<int> indegree(n+1,0);
for(int i=1;i<=n;i++)
{
    for(auto x:g[i])
    {
        indegree[x]++;
    }
}
// doing bfs
queue<int> q;

for(int i=1;i<=n;i++)
{
    if(!indegree[i])
    {
        q.push(i);
    }
}
int index=0;
while(!q.empty())
{
    int p=q.front();
    q.pop();
    order.pb(p);
    index++;
    pos[p]=index;
    for(auto &x:g[p])
    {
        indegree[x]--;
        if(!indegree[x])
        {
            q.push(x);
        }
    }
}

// if there is cycle then oreder size will decree automatically
// ex 1-->2-->3-->4-->1 none of them has indegree zero so the will not be queue intially
// other edges are not connected to it
return order.size()==n;// return false if cycle in directed graph


}

int main()
{

    bolt

int t;
cin>>t;
while(t-->0)
{
cin>>n;
cin>>m;
for(int i=1;i<=n;i++)
{
    g[i].clear();
}

for(int i=1;i<=m;i++)
{
    cin>>con[i];
    cin>>uu[i];
    cin>>vv[i];
    if(con[i]==1)
    {
        g[uu[i]].pb(vv[i]);
    }
}
if(topologicalsort()==false)
{
cout<<"NO"<<endl;

}
else
{
    cout<<"YES"<<endl;
    for(int i=1;i<=m;i++)
    {
if(con[i]==1)
{
cout<<uu[i]<<" "<<vv[i]<<endl;
}
else
{
    if(pos[uu[i]]>pos[vv[i]])
    {
        cout<<vv[i]<<" "<<uu[i]<<endl;
    }
    else
    {
        cout<<uu[i]<<" "<<vv[i]<<endl;
    }

}


    }
}




}

return 0;
}
