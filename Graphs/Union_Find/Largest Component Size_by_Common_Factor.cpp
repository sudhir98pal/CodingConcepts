//Q->link https://leetcode.com/problems/largest-component-size-by-common-factor/
#include<bits/stdc++.h>
using namespace std;

class sudhir
{
public:
    int n;
    int * parent;
    sudhir(int _n)
    {

        this->n=_n;
        this->parent=new int[n+1];
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;

        }
    }

    void unionFind(int x,int y);
    int _find(int x);




};

class Solution
{
    public:
    int largestComponentSize(vector<int> &a)
    {
        int mx=*max_element(a.begin(),a.end());
        sudhir pal(mx);
        for(auto x:a)
        {

            int upper_limit=(int)sqrt(x);
            for(int i=2;i<=upper_limit;i++)
            {

                if(x%i==0)
                {

                    pal.unionFind(x,i);
                    pal.unionFind(x,x/i);
                    /*

                    as let x=6 k=2
                    then 6 6/2=3 and 2 will be in same set

                    */
                }
            }

        }
        unordered_map<int,int> mp;
        int ans=1;
        for(auto x:a)
        {
            mp[pal._find(x)]++;
            ans=max(ans,mp[pal._find(x)]);

        }
return ans;
    }
};
  int sudhir::_find(int x)
    {

        if(parent[x]!=x)
        {
            parent[x]=_find(parent[x]);
        }
        return parent[x];
    }
    void sudhir::unionFind(int x,int y)
    {

        parent[_find(x)]=parent[_find(y)];
        return ;
    }


int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

Solution mysolution;
int ans=mysolution.largestComponentSize(a);
    cout<<ans<<endl;


return 0;
}
