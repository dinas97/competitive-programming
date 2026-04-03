#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN],Tree[4*MAXN],Vis[MAXN];

void Update(ll pos,ll val,ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){Tree[id]=val;return;}
    ll mid=(st+en)/2;
    if(pos<=mid){Update(pos,val,st,mid,2*id);}
    else{Update(pos,val,mid+1,en,2*id+1);}
    Tree[id]=Tree[2*id]+Tree[2*id+1];
}

ll Query(ll l,ll r,ll st=0,ll en=MAXN-1,ll id=1){
    if(en<l||st>r){return 0;}
    if(l<=st&&en<=r){return Tree[id];}
    ll mid=(st+en)/2;
    return Query(l,r,st,mid,2*id)+Query(l,r,mid+1,en,2*id+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n;cin>>n;
    for(ll i=1;i<=2*n;i++){cin>>Arr[i];}
    map<ll,ll>mp;
    for(ll i=1;i<=2*n;i++){
        if(Vis[Arr[i]]){
            Update(Vis[Arr[i]],-1);
            Update(i,1);
            mp[Arr[i]]=Query(Vis[Arr[i]],i);
        }
        else{
            Vis[Arr[i]]=i;
            Update(i,1);
        }
    }

    for(ll i=1;i<=n;i++){cout<<mp[i]<<" ";}

    return 0;
}
