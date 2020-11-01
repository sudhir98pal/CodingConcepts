
// Q link -> https://codeforces.com/contest/1445/problem/C

/*
trick find all prime factors of p is costly thus think in term of prime factors of q as p~10^18 ans q ~10^9
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

vector<ll> findDivisors(ll n)
{
   vector<ll> divisors;
   divisors.pb(n);
    for (ll i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {

            if (n/i == i)
            {
                divisors.pb(i);

            }
            else
            {
            divisors.pb(i);
                divisors.pb(n/i);
            }
        }
    }

    return divisors;
}

int main()
{
     bolt
int t;
cin>>t;
while(t-->0)
{

    ll p,q;
    cin>>p;
    cin>>q;


    ll ans=0;


    // case 1:

    if(p%q!=0)
    {

    cout<<p<<endl;
    continue;
    }


    // case 2 p%q ==0 factors q is subset of factors of p thus
      vector<ll> v=findDivisors(q);
      // find factors of  q

    for(auto x:v)
    {
ll u=p;

while(u%x==0)
{
    u=u/x;

    // divide by factor of q to p if rest number id not divisible by
    // q then it can be ans so take max of it
    if(u%q)
    {
        ans=max(ans,u);
        break;
    }
}



    }
    cout<<ans<<endl;
}





}
