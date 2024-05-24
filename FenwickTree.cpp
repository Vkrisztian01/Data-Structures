#include <iostream>
#include<vector>
#include<algorithm>
#define LSB(S) (S & (-1*S))
typedef long long ll;
using ll = long long;

using namespace std;

ll n,q,a,b,c;

class FenwickTree
{

private:

    vector<ll>T;

public:

    FenwickTree(vector<ll> &v)
     {
        T.assign(v.size(),0);
        for(ll i=1;i<T.size();i++) update(i,v[i]);

     }

    void update(ll i,ll v)
    {
        for(;i<T.size();i+=LSB(i))
        {
            T[i]+=v;
        }
    }

    ll psq(ll i)
    {
        ll ans=0;
        while(i)
        {
            ans+=T[i];
            i-=LSB(i);
        }
        return ans;
    }

    ll rsq(ll l,ll r) {return psq(r)-psq(l-1); }
};

int main()
{
    cin>>n>>q;
    vector<ll>v=vector<ll>(n+1,0);
    for(ll i=1;i<=n;i++) cin>>v[i];
    FenwickTree ft(v);
    while(q--)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
        ft.update(b,c-v[b]);
        v[b]=c;
        }
        else cout<<ft.rsq(b,c)<<"\n";
    }
    return 0;
}
