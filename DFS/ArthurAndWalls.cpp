/*

https://codeforces.com/contest/525/problem/D

*/
#include<bits/stdc++.h>
using namespace std;
char arr[2050][2050];
void dfs(int x,int y)
{
int i,j,c=0;
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        c+=arr[x+i][y+j]=='.';
    }
}
if(c==3)
{
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        arr[x+i][y+j]='.';
    }
}

// all 9 directions
for(i=-1;i<2;i++)
{
    for(j=-1;j<2;j++)
    {
       
        dfs(x+i,y+j);
    }
}


}
}
int main()
{
int n,m;
cin>>n;
cin>>m;
int i,j;
for(i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{

    cin>>arr[i][j];
}
}
for(i=1;i<n;i++)
{
        for(j=1;j<m;j++)
{
    dfs(i,j);
}

}

for(i=1;i<=n;i++)
{
        for(j=1;j<=m;j++)
{
    cout<<arr[i][j];
}
cout<<endl;

}
return 0;
}
