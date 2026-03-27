#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);

    ll n,k;cin>>n>>k;
    for(ll i=1;i<=n;i++){cin>>Arr[i];}
    map<ll,ll>mp;
    ll Ans=0;
    for(ll i=1,j=1;j<=n;j++){
        mp[Arr[j]]++;
        ll mn=(*mp.begin()).first;
        ll mx=(*mp.rbegin()).first;
        while(mx-mn>k&&i<=j){
            mp[Arr[i]]--;
            if(!mp[Arr[i]]){mp.erase(Arr[i]);}
            i++;
            mn=(*mp.begin()).first;
            mx=(*mp.rbegin()).first;
        }
        if(mx-mn<=k){
            Ans+=(j-i+1);
        }
    }
    cout<<Ans<<"\n";

    return 0;
}
