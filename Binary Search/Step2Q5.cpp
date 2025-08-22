#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

db c;

bool good(db r) {
    db sum = r*r + sqrt(r);
    return sum >= c;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>c;
    db l = 1 , r =1e7 ;
    f(i,0,60){
        db m = (l + r)/2;
        if(good(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<setprecision(20)<<r<<'\n';
    return 0;
}