#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define ld long double
#define vsort(v) sort(v.begin(),v.end())
#define vrsort(v) sort(v.begin(),v.end(),greater<int>())
#define mset(a,p) memset(a,p,sizeof(a))
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define mm 500005
#define pi 3.141592653589793238
#define mode  998244353
#define put(c) cout<<c<<endl;
#define ulta(a) reverse(a.begin(),a.end())
#define out(a) for(auto x:a) cout<<x<<" ";
#define sp(arr) sort(arr,arr+sizeof(arr)/sizeof(arr[0]));
#define bolt ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
ll n;
ll k;
ll f[mm];
void pre_calculate()
{
    f[0]=1;
    for(int i=1;i<mm;i++)
    {

        f[i]=(f[i-1]*i)%mode;
    }

}

ll power(ll a,ll b)
{

    ll res=1;
    while(b!=0)
    {
        if(b&1)
        {
            res=(res*a)%mode;
        }
        b>>=1;
        a=(a*a)%mode;

    }

    return res%mode;
}
ll inverse(ll x)
{

    return power(x,mode-2);
}

ll divide(ll x,ll y)
{

    return (x*inverse(y))%mode;
}
ll nCr(ll n,ll k)
{

    if(k>n) return 0;
    ll ans=(f[n-k]*f[k])%mode;
    return  divide(f[n],ans)%mode;
}
int main()
 {

    bolt

    pre_calculate();

cin>>n;
cin>>k;
ll ans=0;
for(ll i=1;i<=n;i++)
{

    ll d=n/i;
    ans=(ans+nCr(d-1,k-1))%mode;
}
cout<<ans<<endl;


 }
