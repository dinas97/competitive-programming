#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MAXN = 1<<20;
ll Arr[MAXN];
double c;

bool f(double x){
    return x*x+sqrt(x)<=c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ;cout.tie(0);
    cout<<fixed<<setprecision(6);

    cin>>c;
    double l=0,r=1e10;
    double x;
    for(ll i=1;i<=100;i++){
        double mid=(l+r)/2;
        if(f(mid)){
            x=mid;
            l=mid+1;
        }
        else{r=mid-1;}
    }
    cout<<x<<"\n";

    return 0;
}
