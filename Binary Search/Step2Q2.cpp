#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )

db n , k ; 
vector<ll> a;

bool good(db m) {
    ll sum = 0;
    f(i,0,n){
        sum += floor(a[i] / m);
    }
    return sum >= k;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>n>>k;
    a.resize(n);
    f(i,0,n){
        cin>>a[i];
    }
    db l = 0 , r = 1e7 + 1;
    f(i,0,100){
        db m = (l + r)/2;
        if(good(m)){
            l = m;
        }else{
            r = m;
        }
    }
    cout<<setprecision(20)<<l<<"\n";
    return 0;
}