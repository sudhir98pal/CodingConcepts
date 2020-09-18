/*
1->Ways to arrange Balls such that adjacent balls are of different types
There are ‘p’ balls of type P, ‘q’ balls of type Q and ‘r’ balls of type
R. Using the balls we want to create a straight line such that no two
 balls of same type are adjacent.

*/

#include<bits/stdc++.h>
using namespace std;
const int mm=100;


int dp[mm][mm][mm][3]; // p,q,r,last(last ball required)


int solve(int p, int q, int r, int last)
{
	// base case
	if (p<0 || q<0 || r<0)
		return 0;


//if last required is p and p is there
	if (p==1 && q==0 && r==0 && last==0)
		return 1;

//if last required is q and q is there
	if (p==0 && q==1 && r==0 && last==1)
		return 1;


//if last required is r any r is there
	if (p==0 && q==0 && r==1 && last==2)
		return 1;




	if (dp[p][q][r][last] != -1)
		return dp[p][q][r][last];



	if (last==0) // at p so line looks like pq..or pr...
        // required is p thus p-1 and after p it can be q or r thus last 1 or 2;
	return dp[p][q][r][last] = solve(p-1,q,r,1) + solve(p-1,q,r,2);


	if(last==1) return dp[p][q][r][last] = solve(p,q-1,r,0) + solve(p,q-1,r,2);

	return dp[p][q][r][last] = solve(p,q,r-1,0) + solve(p,q,r-1,1);


}




int main()
{
    cout<<"Enter the Number of TestCases"<<endl;
    int t;
    cin>>t;
    while(t-->0)
    {
        int p,q,r;
        cout<<"Enter the Value of P"<<endl;
        cin>>p;
        cout<<"Enter the Value of q"<<endl;
        cin>>q;
         cout<<"Enter the Value of r"<<endl;
         cin>>r;


    for(int i=0;i<mm;i++)
    {

        for(int j=0;j<mm;j++)
        {

            for(int k=0;k<mm;k++)
            {

                for(int l=0;l<3;l++)
                {

                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
	int ans=solve(p,q,r,0)+solve(p,q,r,1)+solve(p,q,r,2);// if fast ball is p + if fast ball is q + if fast ball is r
	cout<<ans<<endl;
    }
	return 0;
}
