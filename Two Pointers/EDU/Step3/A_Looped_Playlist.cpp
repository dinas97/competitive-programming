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

    ll n,p;cin>>n>>p;
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>Arr[i];sum+=Arr[i];
        Arr[i+n]=Arr[i];
    }
    ll c=p%sum;
    ll s=0,l=1,r=1e18,res=1,cnt=0;
    for(ll i=1,j=1;j<=2*n&&c;j++){
        s+=Arr[j];
        while(s>=c&&i<=j){
            if(j-i+1<r-l+1){
                l=i,r=j;
                res=l;
                cnt=(r-l+1);
            }
            s-=Arr[i];
            i++;
        }
    }
    cout<<res<<" "<<(p/sum)*n+cnt<<"\n";

    return 0;
}

/*
5 7
1 1 2 2 1
*/
