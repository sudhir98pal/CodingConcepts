#include<bits/stdc++.h>
using namespace std;
class lowerBound
{
public:
    int findlowerbound(int * arr,int arrSize,int low,int high,int numberTobeSearched)
    {

        this->arr=arr;
        this->arrSize=arrSize;
        this->low=low;
        this->high=high;
        this->number=numberTobeSearched;
       return solve();
    }

private:
    int *arr;
    int arrSize;
    int number;
    int low;
    int high;
    int solve();




};

int lowerBound::solve()
{

for(int i=0;i<arrSize;i++)
{

    cout<<arr[i]<<" ";
}
cout<<endl;
    int l=low;
    int r=high;
    int m;
    while(l<r)
    {


         m=l+(r-l)/2;

         if(arr[m]<=number)
         {

             r=m;
         }
         else{
            l=m+1;
         }
    }

        return l;

}
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {

        cout<<"Enter Number of Element"<<endl;
        int n;
        cin>>n;
        int *arr=new int[n];
        cout<<"Enter the elements int arr"<<endl;
        for(int i=0;i<n;i++)
        {

            cin>>arr[i];
        }
        cout<<"Enter the elements to be searched"<<endl;
        int x;
        cin>>x;

        lowerBound pal;
       cout<<pal.findlowerbound(arr,n,0,n-1,x)<<endl;


    }



return 0;
}
