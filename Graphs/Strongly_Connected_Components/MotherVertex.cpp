
/*



1->A mother vertex in a directed graph G = (V,E) is a vertex v such that all
other vertices of Graph can be reached by a directed path from v
2->Undirected connected graph have all vertices as Mother vertex
3->Disconnected Graphs Have No Mother Vertex

4->Concept:Last finished Vertex in Dfs call Is Mother Vertex

*/

#include <bits/stdc++.h>
using namespace std;

class sudhir
{
    private:
	int numberOfVertices;
	vector<int> *g;
    public:
	sudhir(int n)
	{
	    numberOfVertices=n;
	    g=new vector<int>[numberOfVertices];
	}

	void dfs(int n, vector<bool> &vis);

	void makeEdge(int u, int v)
	{
	    g[u].push_back(v);

	}
	int motherVertex();
	// Return -1 If No Mother Vertex Exit
};


void sudhir::dfs(int i,vector<bool> &vis)
{
    vis[i]=true;
    for(auto x:g[i])
    {
        if(vis[x]==false)
        {

            dfs(x,vis);
        }
    }

}




int sudhir::motherVertex()
{

	vector <bool> vis(numberOfVertices, false);


	int motherVertex = 0;


	for (int i = 0; i <numberOfVertices; i++)
	{
		if (vis[i] == false)
		{
			dfs(i, vis);
			motherVertex= i;
		}
	}

	// Now Check whether motherVertex is actually MotherVertex
	for(int i=0;i<numberOfVertices;i++)
    {

        vis[i]=false;
    }
	dfs(motherVertex,vis);
	for (int i=0; i<numberOfVertices; i++)
		if (vis[i] == false)
			return -1;

	return motherVertex;
}


int main()
{
    cout<<"Enter the Number of Vertices In your Graph"<<endl;
    int n;
    cin>>n;
	sudhir pal(n);
	int m;
	cout<<"Enter the Number Of Edges In Your Graph"<<endl;
	cin>>m;
	int u,v;
	while(m-->0)
    {
        cin>>u;
        cin>>v;
        pal.makeEdge(u,v);


    }
    int mVertex=pal.motherVertex();
    if(mVertex!=-1)
    {

        cout<<"Mother Vertex Of your Graph Is "<<mVertex<<endl;
    }
    else{
        cout<<"There is No Mother Vertex In your Graph"<<endl;
    }

	return 0;
}
