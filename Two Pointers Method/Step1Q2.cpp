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
#define ff first
#define ss second
#define mp make_pair

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll n , m;      cin>>n>>m;
    vl a(n + 1) , b(m + 1) , c(m);
    f(i,0,n){
        cin>>a[i];
    }
    f(j,0,m){
        cin>>b[j];
    }
    a[n] = LLONG_MAX , b[m] = LLONG_MAX;
    ll i = 0 , j = 0 , k = 0;
    f(i,0,m){
        while(a[j] < b[i]) j++;
        c[i] = j;
    }
    for(ll x : c){
        cout<<x<<" ";
    }
}