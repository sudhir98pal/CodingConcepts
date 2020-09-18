/*



Minimum number of swaps required to sort an array
This can be easily done by visualizing the problem as a graph. We will have n nodes and an edge directed
from node i to node j if the element at i’th index must be present at j’th index in the sorted array.






*/
#include<bits/stdc++.h>
using namespace std;
class MinimumSwapToSortTheArray
{
    int n;
    int *arr;

    public:
       void takeInput();
       int findMinswap();

};
void MinimumSwapToSortTheArray::takeInput()
{
     cout<<"Enter the number of Element int the Array"<<endl;
    int n_;
    cin>>n_;
    this->n=n_;

    cout<<"Enter the elements of the Array"<<endl;
 arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

}

int MinimumSwapToSortTheArray::findMinswap()
{

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end());

    bool vis[n];
    for(int i=0;i<n;i++)
    {

        vis[i]=false;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {

        if(vis[i]||v[i].second==i) continue;
        // means already swapped or at correct position


        int cycleLength=0;
        int j=i;
        while(vis[j]==false)
        {
            vis[j]=true;
            j=v[j].second;
            cycleLength++;

        }
        ans+=max(0,cycleLength-1);
    }
    return ans;
}



int main()
{
cout<<"Enter the number of test Cases"<<endl;
int t;
cin>>t;
while(t-->0)
{

MinimumSwapToSortTheArray pal;
pal.takeInput();
int x=pal.findMinswap();
cout<<x<<endl;

}


}
