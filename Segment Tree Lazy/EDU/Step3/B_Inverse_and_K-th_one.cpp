#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];

struct node{
    ll mr,x,y;
    node(){mr=0,x=0,y=0;}
};

node Tree[4*MAXN];

void Build(ll st=0,ll en=MAXN-1,ll id=1){
    if(st==en){Tree[id].y=1;return;}
    ll mid=(st+en)/2;
    Build(st,mid,2*id);
    Build(mid+1,en,2*id+1);
    Tree[id].x=Tree[2*id].x+Tree[2*id+1].x;
    Tree[id].y=Tree[2*id].y+Tree[2*id+1].y;
}

void shift(ll id){
    ll left=2*id,right=2*id+1;
    if(Tree[id].mr){
        Tree[left].mr^=1,swap(Tree[left].x,Tree[left].y);
        Tree[right].mr^=1,swap(Tree[right].x,Tree[right].y);
    }
    Tree[id].mr=0;
}

void Update(ll l,ll r,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id);
    if(en<l||st>r){return;}
    if(l<=st&&en<=r){
        Tree[id].mr^=1,swap(Tree[id].x,Tree[id].y);
        return;
    }
    ll mid=(st+en)/2;
    Update(l,r,st,mid,2*id);
    Update(l,r,mid+1,en,2*id+1);
    Tree[id].x=Tree[2*id].x+Tree[2*id+1].x;
    Tree[id].y=Tree[2*id].y+Tree[2*id+1].y;
}

ll Query(ll k,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id);
    if(st==en){return st;}
    ll mid=(st+en)/2;
    if(Tree[2*id].x<=k){
        return Query(k-Tree[2*id].x,mid+1,en,2*id+1);
    }
    else{
        return Query(k,st,mid,2*id);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,m;cin>>n>>m;
    Build();
    while(m--){
        ll t,l,r;
        cin>>t>>l;
        if(t==1){
            cin>>r;
            r--;
            Update(l,r);
        }
        else{cout<<Query(l)<<"\n";}
    }

    return 0;
}

