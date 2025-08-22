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
            if(a[0] > q){
                cout<<0<<'\n';
                break;
            }
            if(a[n - 1] <= q){
                cout<<n<<'\n';
                break;
            }
            if (q >= a[m - 1] && q < a[m]) {
                cout<<m<<'\n';
                break;
            }else if((q < a[m] && q >= a[m - 1])){
                    cout<<m<<'\n';
                    break;
            }else if(q < a[m]){
                r = m; 
            } else{
                l = m; 
            }
        }
    }
}

