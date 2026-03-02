#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];
ll n,x,y;

bool f(ll m){
    ll c1=m/min(x,y);
    ll c2=m/max(x,y);
    return c1+c2>=n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    cin>>n>>x>>y;
    ll l=0,r=max(x,y)*n;
    ll Ans=0;n--;
    while(l<=r){
        ll mid=(l+r)/2;
        if(f(mid)){
            Ans=mid;
            r=mid-1;
        }
        else{l=mid+1;}
    }
    cout<<Ans+min(x,y)<<"\n";

    return 0;
}
