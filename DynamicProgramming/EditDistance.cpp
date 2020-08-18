// Q->LINK->https://leetcode.com/problems/edit-distance/
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

class Sudhir
{
private:
    string word1;
    string word2;
   public:
    Sudhir(string Word1,string Word2)
    {

        word1=Word1;
        word2=Word2;
    }

    int minDistance();

};

int Sudhir::minDistance()
    {

        int n=word1.size();
        int m=word2.size();

        int dp[n+1][m+1];

        // case :: word2's size ==0
        for(int i=0;i<=n;i++)
        {

            dp[i][0]=i;
            // delete the characters of word1 to make word1=word2;

        }

         // case :: word1's size ==0
        for(int i=0;i<=m;i++)
        {

            dp[0][i]=i;
            // delete the characters of word2 to make word1=word2;

        }



        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    // do nothing as equal already;
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    ///   dp[i-1][j-1]=replace
                    ///   dp[i-1][j]=delete
                    /// dp[i][j-1]=insert
                    // all respect to word1
                    dp[i][j]=1+min( dp[i-1][j] , min( dp[i][j-1] , dp[i-1][j-1] ) );
                }

            }
        }


        return dp[n][m];


    }


int main()
{
    bolt
int t;
cin>>t;
while(t-->0)
{
    string s,p;
    cin>>s;
    cin>>p;
    Sudhir pal(s,p);
    cout<<pal.minDistance()<<endl;
}



}



