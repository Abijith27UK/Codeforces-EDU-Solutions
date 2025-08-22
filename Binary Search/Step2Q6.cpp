#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using vl = vector<ll>;

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

str t , p;
ll n , l , r;
vl vec;


bool good(ll m) {
    str rem = "";
    unordered_set<ll> xs;
    f(i,0,m){
        xs.insert(vec[i] - 1);
    }
    f(i,0,n){
        if(xs.find(i) == xs.end()){
            rem += t[i];
        }
    }
    ll p1 = 0 , p2 = 0;
    while( p1 < rem.size() && p2 < p.size()){
        if(rem[p1] == p[p2]){
            p1++;   p2++;
        }else{
            p1++;
        }
    }
    return p2 == p.size() ;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>t>>p;
    n = t.size();
    vec.resize(n);
    f(i,0,n){
        cin>>vec[i];
    }
    l = 0 , r = n ;
    while(r > l + 1){
        ll m = (l + r)/2;
        if(good(m)){
            l = m;
        }else{
            r = m;
        }
    }
    cout<<l<<'\n';
}