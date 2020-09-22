/*
Q link ->https://codeforces.com/problemset/problem/902/B

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
vector<int> g[10005];
int color[10005];
int ans;
/*
Approach

1->fill first node as its color
2->save that color in c(the color=c means all subtree will be of color c);
3->through DFS move to subtree if color[x] is not c update its color to c=color[x] means now subtree of node x has color c and increment ans count(ans++)





*/

void dfs(int x,int c,int p)
{



    if(color[x]!=c)
    {
        ans++;
        c=color[x];
    }


for(int i:g[x])
{
if(i==p) continue;
    dfs(i,c,x);

}

}
int main()
{

    bolt
    int n;
    cin>>n;
    // Note root node is 1
    // start from Node 2 
    for(int i=0;i<n-1;i++)
    {

        int x;
        cin>>x;

        g[i+2].pb(x);
          g[x].pb(i+2);

    }
    for(int i=0;i<n;i++)
    {

        cin>>color[i+1];
    }

    ans=0;
    dfs(1,-1,-1);
    cout<<ans<<endl;



}

