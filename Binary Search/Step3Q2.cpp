#include <bits/stdc++.h>
using namespace std;

#define ll long long
using vl = vector<ll>;
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )


ll n, k , l , r, m;
vl a;

bool good(ll m) {
    ll sum = 0, cnt = 1;
    f(i,0,n){
        if (a[i] > m) return false;
        if (sum + a[i] > m) {
            sum = a[i];
            cnt++;
        } else {
            sum += a[i];
        }
    }
    return cnt <= k;
}

int main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    f(i,0,n)    cin >> a[i];
    l = *max_element(a.begin(), a.end()) , r = accumulate(a.begin(), a.end(), 0LL);
    while (l < r) {
        m = l + (r - l) / 2;
        if (good(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << '\n';
}
