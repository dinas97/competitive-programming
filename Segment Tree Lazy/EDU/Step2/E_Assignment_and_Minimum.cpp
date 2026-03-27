#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN],Brr[MAXN];

struct node{
    ll mr,mn;
    node(){mr=0,mn=0;}
};

node Tree[4*MAXN];

void shift(ll id){
    if(Tree[id].mr){
        Tree[2*id].mr=1;Tree[2*id].mn=Tree[id].mn;
        Tree[2*id+1].mr=1;Tree[2*id+1].mn=Tree[id].mn;
    }
    Tree[id].mr=0;
}

void Update(ll l,ll r,ll val,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id);
    if(st>r||en<l){return;}
    if(l<=st&&en<=r){
        Tree[id].mr=1,Tree[id].mn=val;
        return;
    }
    ll mid=(st+en)/2;
    Update(l,r,val,st,mid,2*id);
    Update(l,r,val,mid+1,en,2*id+1);
    Tree[id].mn=min(Tree[2*id].mn,Tree[2*id+1].mn);
}

ll Query(ll l,ll r,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id);
    if(st>r||en<l){return 1e18;}
    if(l<=st&&en<=r){return Tree[id].mn;}
    ll mid=(st+en)/2;
    return min(Query(l,r,st,mid,2*id),Query(l,r,mid+1,en,2*id+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,m;cin>>n>>m;
    while(m--){
        ll t,l,r,v;
        cin>>t>>l>>r;
        r--;
        if(t==1){
            cin>>v;
            Update(l,r,v);
        }
        else{cout<<Query(l,r)<<"\n";}
    }

    return 0;
}
