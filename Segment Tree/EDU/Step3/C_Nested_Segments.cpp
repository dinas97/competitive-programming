#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN],Tree[4*MAXN];

void Update(ll pos,ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){Tree[id]=1;return;}
    ll mid=(st+en)/2;
    if(pos<=mid){Update(pos,st,mid,2*id);}
    else{Update(pos,mid+1,en,2*id+1);}
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
    map<ll,ll>mp,res;
    for(ll i=1;i<=2*n;i++){
        ll x;cin>>x;
        if(mp[x]){
            res[x]=Query(mp[x],i);
            Update(mp[x]);
        }
        mp[x]=i;
    }
    for(auto r:res){cout<<r.second<<" ";}

    return 0;
}
