#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m , j = 0 , cnt = LLONG_MAX;    cin >> n >> m;
    vl a(n);
    f(i, 0, n) {
        cin >> a[i];
    }
    ll sum = 0;
    f(i,0,n) {
        sum += a[i];
        while(sum - a[j] >= m){
            sum -= a[j];
            j++;
        }
        if(sum>=m){
            cnt = min( cnt , i - j + 1);
        }   
    }
    if (cnt == LLONG_MAX) cout << -1;
    else cout << cnt;
}
