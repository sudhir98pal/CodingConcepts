
#include<bits/stdc++.h>
using namespace std;

//https:// Q->link;leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class lowerBound
{
public:
    int findlowerbound(int * arr,int low,int high,int numberTobeSearched)
    {

        this->arr=arr;
        this->low=low;
        this->high=high;
        this->number=numberTobeSearched;
       return solve();
    }

private:
    int *arr;
    int number;
    int low;
    int high;
    int solve();




};

int lowerBound::solve()
{


    int l=low;
    int r=high;
    int m;

    while(l<=r)
    {


         m=l+((r-l)>>1);

         if(arr[m]<number)
         {

             l=m+1;
         }
         else{
            r=m-1;
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
        // note high = n-1 not n-1;
        cout<<"range"<<endl;
       cout<<pal.findlowerbound(arr,0,n-1,x)<<endl;

  cout<<pal.findlowerbound(arr,0,n-1,x+1)-1<<endl;

    }



return 0;
}
