#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double

using vl = vector<ll>;
using vd = vector<db>;

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

ll n;
db l = 0, r = 2e18 , m;
vd x , v;

bool good(db t){
    db mini = -1e18 , maxi = 1e18;
    f(i,0,n){
        mini = max( (x[i] - v[i]*t) , mini );
        maxi = min( (x[i] + v[i]*t) , maxi );
    }
    return mini <= maxi;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>n;
    x.resize(n);    v.resize(n);
    f(i,0,n){
        cin>>x[i]>>v[i];
    }
    f(i,0,100){
        m = (l + r)/2.0;
        if(good(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<setprecision(10)<<r;
}