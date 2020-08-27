


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class edge
{
    public:
    ll source;
    ll destination;
    ll weight;
};


class sudhir
{
    public:
    ll numberOfEdges;
    ll numberOfVertices;
    edge * g;
    ll * parent;
    sudhir(ll e,ll n )
    {

        numberOfEdges=e;
        numberOfVertices=n;
        g=new edge[numberOfEdges];
        parent=new ll[numberOfVertices+1];
    }

    void init();
    ll root(ll x);
    void makeUnion(ll x,ll y);
    ll KrushalMst();




};
void sudhir::init()
{

    for(ll i=0;i<=numberOfVertices;i++)
    {

        parent[i]=i;
    }
}

ll sudhir::root(ll x)
{
    while(parent[x]!=x)
    {

        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}

void sudhir::makeUnion(ll x,ll y)
{
    ll xx=root( x);
    ll yy=root( y);
    parent[xx]=parent[yy];
}
bool comp(const edge &a,const edge &b)
{
    return a.weight<=b.weight;
}

ll sudhir::KrushalMst()
{

// Sort All Edges Acc. To Their Weights

sort(g,g+numberOfEdges,comp);



    ll minCost=0;
    init();
    for(ll i=0;i<numberOfEdges;i++)
    {

        ll x=g[i].source;
        ll y=g[i].destination;


        if(root(x)!=root(y))
        {// there is no cycle formed by this edge include it;

            minCost+=g[i].weight;

            makeUnion(x,y);
        }
    }

    return minCost;
}
int main()
{

int tt;
cin>>tt;
while(tt-->0)
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
    int x,y,w;
    cin>>x;
    cin>>y;
    cin>>w;

    pal.g[t].source=x;
    pal.g[t].destination=y;
    pal.g[t].weight=w;

}
cout<<pal.KrushalMst()<<endl;
}


}

