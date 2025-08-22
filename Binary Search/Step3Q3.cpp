#include <bits/stdc++.h>
using namespace std;

#define ll long long
using vl = vector<ll>;
#define f(i, a, b) for (ll i = a; i < b; i++)

ll n, k, l, r, m;
vl a;

bool good(ll m) {
    ll start = a[0], cnt = 1;
    for (ll i = 1; i < n; i++) {
        if (a[i] - start >= m) {
            start = a[i]; 
            cnt++;
            if (cnt == k) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    l = 0, r = a[n - 1] - a[0];
    while (l < r) {
        m = l + (r - l + 1) / 2;
        if (good(m)) {
            l = m; 
        } else {
            r = m - 1; 
        }
    }
    cout << l << '\n';
}
