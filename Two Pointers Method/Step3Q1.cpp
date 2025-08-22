#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vd = vector<db>;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#define f(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = b; i > a; --i)
#define all(n) n.begin(), n.end()

const int MOD = 1e9 + 7;

ll n, p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    vi v(n);
    ll total = 0;

    for (auto &x : v) {
        cin >> x;
        total += x;
    }

    ll ans = ((p - v[0]) / total) * n + 1;
    ll sum = ((p - v[0]) / total) * total + v[0];
    int l = 0, pos = 0;

    if (sum >= p) {
        l = pos = 0;
    } else {
        rf(i, -1, n - 1) {
            sum += v[i];
            ++ans;
            if (sum >= p) {
                pos = l = i;
                break;
            }
        }
    }

    ll len = ans;
    f(r, 1, n) {
        sum += v[r];
        ++len;
        while (sum >= p) {
            sum -= v[l++];
            l %= n;
            --len;
        }
        if (len + 1 < ans) {
            pos = (l - 1 + n) % n;
            ans = len + 1;
        }
    }

    cout << pos + 1 << " " << ans;
}
