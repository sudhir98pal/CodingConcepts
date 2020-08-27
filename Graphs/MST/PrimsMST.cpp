

#include<bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
using namespace std;




class sudhir
{
    public:
    ll numberOfEdges;
    ll numberOfVertices;
    vector<pll>* g;

    sudhir(ll e,ll n )
    {

        numberOfEdges=e;
        numberOfVertices=n;
        g=new vector<pll>[numberOfEdges+1];
    }



    ll PrimsMst(ll x);




};







ll sudhir::PrimsMst(ll x)
{
ll minCost=0;
bool vis[numberOfVertices+1];
for(int i=0;i<=numberOfVertices;i++)
{
    vis[i]=false;
}

priority_queue<pll,vector<pll>,greater<pll>> q;

q.push({0,x});
// pair={weight,node}

while(!q.empty())
{

    pll p=q.top();
    q.pop();
    ll u=p.second;
    if(vis[u]) continue;

    minCost+=p.first;

    vis[u]=true;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].second;
        if(vis[v]==false)
        {
            q.push(g[u][i]);
        }
    }

}
return minCost;


}
int main()
{


    ll n;
cout<<"Enter Number Of Vertices In The graph"<<endl;
cin>>n;
ll e;
cout<<"Enter the Number of Edges in The graph"<<endl;
cin>>e;

sudhir pal(e,n);

for(ll t=0;t<e;t++)
{
    ll x,y,w;
    cin>>x;
    cin>>y;
    cin>>w;
    // pair={weight,node}
pal.g[x].push_back({w,y});
pal.g[y].push_back({w,x});


}
cout<<pal.PrimsMst(1)<<endl;



}

