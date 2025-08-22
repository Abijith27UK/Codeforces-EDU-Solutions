#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()

ll n;
ll s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    vi w(n),c(n);
    f(i,0,n)    cin>>w[i];
    f(i,0,n)    cin>>c[i];
    ll l = 0;
    ll cost = 0, weight = 0 ,ans=0;
    f(r, 0, n) {
        weight += w[r]; cost += c[r];
        while (weight > s){
            weight -= w[l];
            cost -= c[l];
            l++;
        } 
        ans = max(ans,cost);
    }

    cout << ans;
}
