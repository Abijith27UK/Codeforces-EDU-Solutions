#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll w,h,n;   cin>>w>>h>>n;
    ll l = 0 , r = 1;
    while((r/w)*(r/h) < n){
        r *= 2;
    }
    while(r > l + 1){
        ll m = (l + r)/2;
        if((m/w)*(m/h) >= n){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<r;
}