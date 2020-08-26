/*

Detect Cycle in an Undirected Graph using Union Find

No self edge is Allowed



*/





#include<bits/stdc++.h>

using namespace std;

class edge
{
    public:
    int source;
    int destination;

};

class mygraph
{

public:
    int numberOfVertices;
    int numberOfEdges;
     edge* g;
    mygraph(int vertices,int edges)
    {
        numberOfEdges=edges;
        numberOfVertices=vertices;
        g=new edge[(sizeof(edge))*(edges)];
        // as A single node can connect (all edges)
        // thus space required edges*sizeof(edge)


    }

    bool isCycle();
    int findSubset(int *parent,int u);
    void makeUnion(int *parent,int u,int v);
};

bool mygraph::isCycle()
{
    int *parent=new int[numberOfVertices];

    // Initially all subsets are as single element sets
    for(int i=0;i<numberOfVertices;i++)
    {
        parent[i]=-1;
    }

    // Iterate through all edges of graph, find subset of source
    // and destination of every edge, if both subsets are same, then
    // there is cycle in graph.

    for(int i=0;i<numberOfEdges;i++)
    {
    int sources_set=findSubset(parent,g[i].source);
    int destination_set=findSubset(parent,g[i].destination);
    if(sources_set==destination_set)
    {
        return true;
    }

    makeUnion(parent,sources_set,destination_set);
    }



    return false;
}

int mygraph::findSubset(int *parent,int u)
{

if(parent[u]==-1) return u;
return findSubset(parent,parent[u]);

}


void mygraph::makeUnion(int *parent ,int u,int v)
{
    int uset=findSubset(parent,u);
    int vset=findSubset(parent,v);
    if(uset!=vset)
    {
        parent[uset]=vset;
    }
}
int main()
{

cout<<"Enter the Number of Vertices In the graph"<<endl;
int v;
cin>>v;

cout<<"Enter the Number of Edges In the graph"<<endl;
int e;
cin>>e;

mygraph sudhir(v,e);

for(int i=0;i<e;i++)
{

    cout<<"Enter Source "<<endl;
    int u,v;
    cin>>u;
    cout<<"Enter Destination"<<endl;
    cin>>v;

    if(u==v)
    {
        cout<<"NO Self Edges are allowed"<<endl;
        i-=1;
    }
    u--;
    v--;
    // vertices are entered from 1...n
    sudhir.g[i].source=u;
     sudhir.g[i].destination=v;


}

if(sudhir.isCycle())
{
    cout<<"There Is Cycle In The Graph"<<endl;
}
else{
    cout<<"No Cycle In The Graph"<<endl;
}




}



