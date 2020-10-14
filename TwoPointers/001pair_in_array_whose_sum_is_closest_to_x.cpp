



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
class sudhir
{
public:

    int * arr;
    int target;
    int n;
    sudhir(int n,int target)
    {

        this->target=target;
        this->n=n;
        arr=new int[n];
    }

    void findClosestSumPair();

};

void sudhir::findClosestSumPair()
{
sp(arr) // sorting
    int diff=10000;// max possible

    int l=0;
    int r=n-1;
    int firstNumber;
    int secondNumber;

    while(l<r)
    {
        int tempDiff=abs(arr[l]+arr[r]-target);
        if(tempDiff<diff)
        {

            firstNumber=arr[l];
            secondNumber=arr[r];
        }

        if(arr[l]+arr[r]>target) r--;
        else l++;


    }



cout<<firstNumber<<" "<<secondNumber<<endl;


}

int main()
{
     bolt
     cout<<"Enter Number of test cases"<<endl;
int t;
cin>>t;

while(t-->0)
{
    cout<<"Enter The value of N"<<endl;
int n;
cin>>n;

int target;
cout<<"Enter The value of target"<<endl;
cin>>target;
sudhir pal(n,target);



rep(i,n)
{

    cin>>pal.arr[i];
}

pal.findClosestSumPair();



}




}

