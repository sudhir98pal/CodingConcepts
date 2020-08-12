
//Q-> LINK:-> https://codeforces.com/problemset/problem/427/C

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
const int mm=100001;

int cost[mm];
class sudhir
{
int V;

list<int> *graph;

void fillOrder(int x,bool vis[],stack<int> &st);

vector<int> dfs(int x,bool vis[],vector<int> &v);

public:
    sudhir(int v);

    void addEdge(int x,int y);

    vector<vector<int>> printStronglyConnectedGraph();

    sudhir getTransposeOfGraph();





};

sudhir::sudhir(int v)
{
    this->V=v;
    graph=new list<int>[V];
}

vector<int>  sudhir::dfs(int x,bool vis[],vector<int> &v)
{

    vis[x]=true;

  v.pb(x);
    for(auto i:graph[x])
        {
if(vis[i]==false)
{
    dfs(i,vis,v);
}
    }

    return v;
}

sudhir sudhir::getTransposeOfGraph()
{


    sudhir pal(V);
    for(int i=0;i<V;i++)
    {
        for(auto x:graph[i])
        {
            pal.graph[x].pb(i);
        }
    }
    return pal;
}

void sudhir::addEdge(int x,int y)
{
    graph[x].pb(y);
}

void sudhir::fillOrder(int x,bool vis[],stack<int> &st)
{
vis[x]=true;
for(auto i:graph[x])
    {
        if(vis[i]==false)
        {

            fillOrder(i,vis,st);
        }
    }
    st.push(x);

}

 vector<vector<int>> sudhir::printStronglyConnectedGraph()
{
    stack<int> st;
    bool vis[V];
    rep(i,V) vis[i]=false;
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        {
            fillOrder(i,vis,st);
        }
    }

    sudhir pal=getTransposeOfGraph();
    rep(i,V) vis[i]=false;
    vector<vector<int>> v1;
    while(!st.empty())
    {

        int v=st.top();
        st.pop();
        if(vis[v]==false)
        {
            vector<int> v2;
           vector<int> v3= pal.dfs(v,vis,v2);

           if(v3.size()>0)
           {
               v1.pb(v3);
           }

        }
    }

    return v1;

}

int main()
{

int n;
cin>>n;
//n number of junctions in the graph;
rep(i,n)
{
   cin>>cost[i];
}
int m;
cin>>m;
sudhir pal(n);
   int x,y;
rep(i,m)
{

    cin>>x;
    cin>>y;
    x--;
    y--;
    pal.addEdge(x,y);

}


vector<vector<int>> v=pal.printStronglyConnectedGraph();
ll ans=0;

ll r=1;
for(auto x:v)
{
    unordered_map<int,int> mp;
    int c=INT_MAX;


    for(auto y:x)
    {
     c=min(c,cost[y]);
        mp[cost[y]]++;
    }


if(c!=INT_MAX)
{
    ans+=c;
   r=r*mp[c];
r%mode;
}

}

cout<<ans<<" "<<r%mode<<endl;




return 0;
}
