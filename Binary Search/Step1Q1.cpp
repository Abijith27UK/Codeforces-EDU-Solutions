#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,k; cin>>n>>k;
    ll a[n];
    f(i,0,n){
        cin>>a[i];
    }
    while(k--){
        ll q;   cin>> q ;
        ll l = -1, r = n, cnt = 0;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (q == a[m]){
                cout<<"YES"<<'\n';
                cnt++;
                break;
            } else if (q < a[m]) {
                r = m; 
            } else {
                l = m; 
            }
        }
        if(cnt==0){
            cout<<"NO"<<'\n';
        }
    }
}

