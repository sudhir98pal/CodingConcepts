#include<bits/stdc++.h>
using namespace std;

struct Meeting
{
int start;
int end;
int pos;
};

int main()
 {
	//code
	
	int t;
	cin>>t;
	while(t-->0)
	{
	    int n;
	    cin>>n;
	    Meeting arr[n];
	    int s[n];
	    int f[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    
	       for(int i=0;i<n;i++)
	    {
	        cin>>f[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        arr[i].start=s[i];
	        arr[i].end=f[i];
	        arr[i].pos=i+1;
	        
	       
	    }
	    
	    sort(arr,arr+sizeof(arr)/sizeof(arr[0]),[](const Meeting &a,const Meeting &b)->bool{
return a.end<=b.end;	        
	    });
	    
	    int last=arr[0].end;
	    cout<<arr[0].pos<<" ";
	    
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i].start>=last)
	        {
	            last=arr[i].end;
	            cout<<arr[i].pos<<" ";
	        }
	    }
	    cout<<endl;
	    
	    
	}
	return 0;
}
