#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Size[MAXN],Par[MAXN];

struct node{
    ll u,v,w;
    node(){u=0,v=0,w=0;}
};

node Arr[MAXN];

bool comp(node a,node b){
    return a.w<b.w;
}

ll Get_root(ll x){
    if(Par[x]==x){return x;}
    return Par[x]=Get_root(Par[x]);
}

void Union_set(ll v,ll u){
    v=Get_root(v),u=Get_root(u);
    if(Size[v]>Size[u]){swap(u,v);}
    Par[v]=u;Size[u]+=Size[v];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,m;cin>>n>>m;
    for(ll i=1;i<=n;i++){
        Par[i]=i,Size[i]=1;
    }
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>Arr[i].u>>Arr[i].v>>Arr[i].w;
    }
    sort(Arr+1,Arr+1+m,comp);
    ll Ans=0;
    for(ll i=1;i<=m;i++){
        ll u=Arr[i].u,v=Arr[i].v;
        if(Get_root(u)!=Get_root(v)){
            Ans+=Arr[i].w;
            Union_set(u,v);
        }
    }
    cout<<Ans<<"\n";


    return 0;
}
