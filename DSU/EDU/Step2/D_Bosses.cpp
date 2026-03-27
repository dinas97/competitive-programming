#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN],Par[MAXN],Val[MAXN],Size[MAXN];

ll Get_root(ll x){
    if(Par[x]==x){return x;}
    return Get_root(Par[x]);
}

void Union_set(ll u,ll v){
    u=Get_root(u),v=Get_root(v);
    if(Size[u]<=Size[v]){
        Par[u]=v;Size[v]+=Size[u];
        Val[u]+=1;Val[u]-=Val[v];
    }
    else{
        Par[v]=u;Size[u]+=Size[v];
        Val[u]+=1;Val[v]-=Val[u];
    }
}

ll Get_ans(ll x){
    if(Par[x]==x){return Val[x];}
    return Val[x]+Get_ans(Par[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,m;cin>>n>>m;
    for(ll i=1;i<=n;i++){Par[i]=i,Size[i]=1,Val[i]=0;}

    while(m--){
        ll t,a,b;cin>>t>>a;
        if(t==1){
            cin>>b;
            Union_set(a,b);
        }
        else{
            cout<<Get_ans(a)<<"\n";
        }
    }

    return 0;
}
