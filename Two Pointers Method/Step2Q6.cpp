#include <bits/stdc++.h>
using namespace std;

#define ll long long
using vl = vector<ll>;

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()

struct stack {
    vl s , smin = {LLONG_MAX} , smax = {LLONG_MIN};
    
    void push(ll x){
        s.push_back(x);
        smin.push_back(::min(smin.back() , x));
        smax.push_back(::max(smax.back() , x));
    }
    
    ll pop() {
        ll res = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }
    
    bool empty() {
        return s.empty();
    }
    
    ll min() {
        return smin.back();
    }
    
    ll max() {
        return smax.back();
    }
};

::stack s1 , s2;

ll n , k , num = 0 , cnt = 0; 
ll mp[100001] ;

bool good(){
    ll mn = min(s1.min() , s2.min());
    ll mx = max(s1.max() , s2.max());
    return mx - mn <= k;
}

void add(ll x){
    s2.push(x);
}

void rm(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
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
        while(!good()){
            rm();
            l++;
        }
        cnt += r - l + 1;
    }
    cout<<cnt;
}