/*

Given weights and values of n items, put these items in a
knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1]
which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity,
find out the maximum value subset of val[] such that sum of the weights
of this subset is smaller than or equal to W. You cannot break an item,
either pick the complete item or don’t pick it (0-1 property).

*/
#include<bits/stdc++.h>
using namespace std;
const int mx=125;
int dp[mx][mx];
int knapsack_01(int wt[],int val[],int capacity,int n)
{

    if(capacity==0||n==0) return 0;
    if(dp[capacity][n]!=-1) return dp[capacity][n];
    if(wt[n-1]>capacity)
    {


        return dp[capacity][n-1]=knapsack_01(wt,val,capacity,n-1);
    }


    return dp[capacity][n]=max(val[n-1]+knapsack_01(wt,val,capacity-wt[n-1],n-1),knapsack_01(wt,val,capacity,n-1));


    /*

   ---------- OR ------------------

    int knapack_01(int wt[], int val[],int capacity, int n)
{
    int i, w;
    int K[n + 1][capacity + 1];


    for (i = 0; i <= n; i++)
        {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(
                    val[i - 1] + K[i - 1][w - wt[i - 1]],
                    K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][capacity];
}










    */

}

int main()
{

for(int i=0;i<mx;i++)
{

    for(int j=0;j<mx;j++)
    {

        dp[i][j]=-1;
    }

}

    int val[] = { 10, 20, 30 };
    int wt[] = { 1, 1, 1 };
    int capacity= 2;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<knapsack_01(wt,val,capacity,n)<<endl;

return 0;
}
