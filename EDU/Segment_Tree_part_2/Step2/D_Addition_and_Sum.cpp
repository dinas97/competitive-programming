#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];

struct node{
    ll mr,add,value;
    node(){mr=0,add=0,value=0;}
};

node Tree[4*MAXN];

void shift(ll id,ll st,ll en){
    ll left=2*id,right=2*id+1;
    ll mid=(st+en)/2;
    if(Tree[id].mr){
        Tree[left].mr=1,Tree[left].add+=Tree[id].add,Tree[left].value+=(Tree[id].add*(mid-st+1));
        Tree[right].mr=1,Tree[right].add+=Tree[id].add,Tree[right].value+=(Tree[id].add*(en-mid));
    }
    Tree[id].mr=0,Tree[id].add=0;
}

void Update(ll l,ll r,ll val,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id,st,en);
    if(en<l||st>r){return;}
    if(l<=st&&en<=r){
        Tree[id].mr=1,Tree[id].add+=val,Tree[id].value+=(val*(en-st+1));
        return;
    }
    ll mid=(st+en)/2;
    Update(l,r,val,st,mid,2*id);
    Update(l,r,val,mid+1,en,2*id+1);
    Tree[id].value=Tree[2*id].value+Tree[2*id+1].value;
}

ll Query(ll l,ll r,ll st=0,ll en=MAXN-1,ll id=1){
    shift(id,st,en);
    if(en<l||st>r){return 0;}
    if(l<=st&&en<=r){return Tree[id].value;}
    ll mid=(st+en)/2;
    return Query(l,r,st,mid,2*id)+Query(l,r,mid+1,en,2*id+1);
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
        else{
            cout<<Query(l,r)<<"\n";
        }
    }

    return 0;
}
