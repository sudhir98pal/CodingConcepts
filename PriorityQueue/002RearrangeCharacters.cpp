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
class Alpha
{
public:
char name;
int freq;
Alpha(char c,int freq)
{

    this->freq=freq;
    this->name=c;
}

};

class compare
{
public:
    bool operator()(Alpha first,Alpha second)
    {

        return first.freq<=second.freq;
    }
};
void Rearrange(string s)
{
    priority_queue<Alpha,vector<Alpha>,compare> pq;
    int AlphaCount[26];
    for(int i=0;i<26;i++)
    {

        AlphaCount[i]=0;
    }
int n=s.size();
    for(auto x:s)
    {

        AlphaCount[x-'a']++;
    }

    for(int i=0;i<26;i++)
    {

        char c=('a'+i);
        if(AlphaCount[i]>0)
        {
               Alpha alpha(c,AlphaCount[i]);
        pq.push(alpha);

        }

    }

    s="";
    Alpha pre('%',-1);
    while(!pq.empty())
    {

        Alpha alpha=pq.top();

        pq.pop();
        s+=alpha.name;
        if(pre.freq>0)
        {

            pq.push(pre);
        }

       (alpha.freq)--;
        pre=alpha;
    }


if(n!=s.size())
{

    cout<<"Not Possible to  Rearrange The given string"<<endl;
}
else{
    cout<<s<<endl;
}

}
int main()
{
     bolt
string s;
cin>>s;
Rearrange(s);




}

