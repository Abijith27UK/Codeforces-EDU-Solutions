#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll n, m;    cin >> n >> m;
    vector<ll> a(n), b(m);
    f(i,0,n){
        cin >> a[i];
    }
    f(i,0,m){
        cin >> b[i];
    }
    ll i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            ++j;
        } else if (a[i] < b[j]) {
            ++i;
        } else {
            ll a_cnt = 0, b_cnt = 0 , val = a[i];
            while (i < n && a[i] == val) {
                ++a_cnt;
                ++i;
            }
            while (j < m && b[j] == val) {
                ++b_cnt;
                ++j;
            }
            cnt += (a_cnt) * (b_cnt);
        }
    }
    cout << cnt ;
}