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

ll k , n , l = 0 , r = 26 * 1e9 ;
vl a;

bool good(ll m) {
    ll sum = 0;
    f(i,0,n){
        //here we wanna create m grp and need to check if no of members in m grps is > k
        //if it is greater than k then it is we can create more grp with k members
        if(a[i] > m){
            sum += m;   //as we want to create m grps and if a[i] > m then 
            //they can contribute for m grps
        }else{
            sum += a[i]; //as a[i]<m they can contribute for only a[i] grps
        }
    }
    return (sum/m) >= k ;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>k>>n;
    a.resize(n);
    f(i,0,n){
        cin>>a[i];
    }
    // l = 0 , r = n ;
    while(r > l + 1){
        ll m = (l + r)/2;
        if(good(m)){
            l = m;
        }else{
            r = m;
        }
    }
    cout<<l<<'\n';
    return 0;
}