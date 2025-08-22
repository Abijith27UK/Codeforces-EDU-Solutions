#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vd = vector<db>;
#define pb push_back

#define mp make_pair

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, k; 
    cin >> n;
    ll a[n];
    f(i,0,n) {
        cin >> a[i];
    }
    sort(a , a + n);
    cin>>k;
    while (k--) {
        ll l , r ;       cin>>l>>r;
        ll low1 = -1, high1 = n ;
        while(high1 - low1 > 1){
            ll  mid = (high1 + low1)/2;
            if(a[mid]<l){
                low1 = mid; 
            }else{
                high1 = mid;
            }
        }
        ll low2 = -1, high2 = n ;
        while(high2 - low2 > 1){
            ll  mid = (high2 + low2)/2;
            if(a[mid]>r){
                high2 = mid; 
            }else{
                low2 = mid;
            }
        }
        cout<<high2 - high1<<" ";
    }
}
