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

    ll n;cin>>n;
    for(ll i=1;i<=n;i++){cin>>Arr[i];}
    ll gcd=0,l=1,g=0,Ans=1e18;
    for(ll i=1;i<=n;i++){
        gcd=__gcd(gcd,Arr[i]);
        g=0;
        while(gcd==1){
            for(ll j=i;j>=l;j--){
                if(__gcd(g,Arr[j])==1){
                    gcd=g;
                    l=j;
                    break;
                }
                g=__gcd(g,Arr[j]);
            }
            Ans=min(Ans,i-l+1);
        }
    }
    Ans=Ans==1e18?-1:Ans;
    cout<<Ans<<"\n";

    return 0;
}
