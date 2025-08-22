#include <bits/stdc++.h>
using namespace std;

#define ll long long
using vl = vector<ll>;

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()

struct stack {
    vl s , s_gcd = {0} ;
    
    void push(ll x){
        s.push_back(x);
        s_gcd.push_back(__gcd(s_gcd.back() , x));
    }
    
    void pop() {
        s.pop_back();
        s_gcd.pop_back();
    }
    
    ll back() {
        return s_gcd.back();
    }
    
    bool empty() {
        return s.empty();
    }
};

::stack s1 , s2;

ll n; 

bool good(){
    return __gcd(s1.back() , s2.back()) == 1;
}

void add(ll x){
    s2.push(x);
}

void rm(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.s.back());
            s2.pop();
        }
    }
    s1.pop();
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>n;
    vl a(n);
    f(i,0,n){
        cin>>a[i];
    }
    ll l = 0 , ans = n + 1;
    f(r,0,n){
        add(a[r]);
        while(good()){
            rm();
            ans = min(ans,r - l + 1);
            l++;
        }
        
    }
    if(ans>n){
        cout<<-1;
    }else{
        cout<<ans;
    }
}