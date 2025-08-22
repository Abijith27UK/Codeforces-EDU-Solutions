#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

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

ll n, s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> s;
    vl a(n);
    ll l = 0,sum = 0,ans = 0;
    f(i, 0, n) {
        cin >> a[i];
    }
    f(r, 0, n) { 
        sum+=a[r];
        while(sum > s){
            sum-=a[l++];
        }
        ans += ((r - l + 1)*(r - l + 2)) / 2;
        //cout<<ans<<" "<<l<<endl;
    }
    cout<<ans;
}
