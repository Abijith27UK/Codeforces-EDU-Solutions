#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using vl = vector<ll>;

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

str s;
ll nb , ns , nc , pb , ps , pc , l , r , money , n , cnt_B = 0 , cnt_S = 0 , cnt_C = 0;
ll cnt;

bool good(ll m) {
    ll price = max(cnt_B*m - nb , 0LL)*pb + max(cnt_S*m - ns , 0LL)*ps + max(cnt_C*m - nc , 0LL)*pc;
    return money >= price ;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>s>>nb>>ns>>nc>>pb>>ps>>pc>>money;
    n = s.size();
    f(i,0,n){
        if(s[i] == 'B'){
            cnt_B++;
        }else if(s[i] == 'S'){
            cnt_S++;
        }else{
            cnt_C++;
        }
    }
    
    l = 0 , r = 1e13 + 10 ;
    while(r > l + 1){
        ll m = (l + r)/2;
        if(good(m)){
            l = m;
        }else{
            r = m;
        }
    }
    cout<<l + cnt<<'\n';
}