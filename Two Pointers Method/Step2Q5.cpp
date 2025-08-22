#include <bits/stdc++.h>
using namespace std;

#define ll long long
using vl = vector<ll>;

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()

ll n , k , num = 0 , cnt = 0; 
ll mp[100001] ;

bool good(ll x){
    return x <= k;
}

void add(ll x){
    mp[x]++;
    if(mp[x] == 1) num++;
}

void rm(ll x){
    if(mp[x] > 0){
        mp[x]--;
        if(mp[x] == 0) num--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>n>>k;
    vl a(n);
    f(i,0,n){
        cin>>a[i];
    }
    ll l = 0;
    f(r,0,n){
        add(a[r]);
        while(!good(num)){
            rm(a[l]);
            l++;
        }
        cnt += r - l + 1;
    }
    cout<<cnt;
}