#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, k; 
    cin >> n >> k;
    ll a[n];
    f(i,0,n) {
        cin >> a[i];
    }
    while (k--) {
        ll q;   
        cin >> q;
        ll l = -1, r = n;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (a[m] < q) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << r + 1 << endl;
    }
}
