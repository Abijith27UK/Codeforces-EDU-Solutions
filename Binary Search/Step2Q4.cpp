#include <bits/stdc++.h>
using namespace std;

#define ll long long

using vl = vector<ll>;

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

ll m , n;
vl t , y , z;

bool good(ll T) {
    ll sum = 0;
    f(i,0,n){
        ll total_cycles = T / (t[i] * z[i] + y[i]);  
        ll remaining_time = T % (t[i] * z[i] + y[i]);
        ll work_time = total_cycles * z[i];
        work_time += min(remaining_time / t[i], z[i]);
        sum += work_time;
    }
    return sum >= m;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>m>>n;
    t.resize(n); 
    y.resize(n); 
    z.resize(n);
    ll min_time = 100;
    f(i,0,n){
        cin>>t[i]>>z[i]>>y[i];
        if(t[i] < min_time){
            min_time = t[i];
        }
    }
    if(m == 0) {
        cout << 0 << endl;
        f(i,0,n) {
            cout << "0 ";
        }
        return 0;
    }
    ll l = 0 , r =1e7 ;
    while(r > l + 1){
        ll m = (l + r)/2;
        if(good(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<r<<'\n';
    vl ans(n);
     ll blown = 0;
    f(i,0,n){
        ans[i] = (r / (t[i] * z[i] + y[i]))* z[i] + min((r % (t[i] * z[i] + y[i])) / t[i], z[i]);
        if(blown + ans[i] > m) {
            if(m > 0) {
                cout << m-blown << " ";
                m = 0;
            }
            else cout << "0 ";
        }else{ 
            cout << ans[i] << " ";
            blown += ans[i];
        }
    }
}