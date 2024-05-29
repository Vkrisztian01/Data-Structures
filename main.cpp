#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using ll = long long;

using namespace std;

ll n,m,a,b;
ll st[21][200001];

void build()
{
    for(ll i=1;i<=20;i++)
    {
        for(ll j=1;j<n;j++)
        {
            st[i][j]=max(st[i-1][j],st[i-1][j+1]);
        }
        st[i][n]=st[i-1][n];
    }
}

ll query(ll a,ll b)
{
    if(b<a) swap(a,b);
    ll ans=max(st[0][a],st[0][b]);
    for(int i=20;i>=0;i--)
    {
        if(a+(1<<i)<=b)
        {
            ans=max(st[i][a],ans);
            a+=(1<<i);
        }
    }
    ans=max(ans,st[0][b]);
    return ans;
}

int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>st[0][i];
    build();
    while(m--)
    {
        cin>>a>>b;
        cout<<query(a,b)<<"\n";
    }
    return 0;
}
