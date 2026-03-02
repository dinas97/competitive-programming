#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];
ll Tree[4*MAXN];

void Update(ll pos,ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){Tree[id]=1;return;}
    ll mid=(st+en)/2;
    if(pos<=mid){
        Update(pos,st,mid,2*id);
    }
    else{
        Update(pos,mid+1,en,2*id+1);
    }
    Tree[id]=Tree[2*id]+Tree[2*id+1];
}

ll Query(ll val,ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){return Tree[id];}
    ll mid=(st+en)/2;
    if(val<=mid){
        return Query(val,st,mid,2*id)+Tree[2*id+1];
    }
    else{
        return Query(val,mid+1,en,2*id+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n;cin>>n;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        cout<<Query(x)<<" ";
        Update(x);
    }

    return 0;
}
