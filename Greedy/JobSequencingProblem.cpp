/*
Step 1-> sort acc to profit
step 2-> min(n,job[i].dead) to 0 find free slot book it and mark notfree and break loop as max can be n jobs thus taking min with n.
*/


#include<bits/stdc++.h>
using namespace std;
class job
{
    public:
    int id;
    int dead;
    int profit;
    
    
};
int main()
 {
int t;
cin>>t;
while(t-->0)
{
    int n;
    cin>>n;
    job arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].id;
        cin>>arr[i].dead;
        cin>>arr[i].profit;
    }
    sort(arr,arr+sizeof(arr)/sizeof(arr[0]),[](const job&a,const job&b)->bool
    {
        return a.profit>b.profit;
    });
 
   
 
    int maxProfit=0;
    int numberOfjobsDone=0;
    int vis[n];
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].dead)-1;j>=0;j--)
        {
            if(vis[j]==false)
            {
                maxProfit+=arr[i].profit;
                numberOfjobsDone++;
                vis[j]=true;
         
                break;
            }
        }
    }
    
    cout<<numberOfjobsDone<<" ";
    cout<<maxProfit<<endl;
}
	return 0;
}
