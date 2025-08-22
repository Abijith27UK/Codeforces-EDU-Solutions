#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m;    
    cin >> n >> m; 
    ll a[n] , b[m];
    f(ii,0,n){
        cin>>a[ii];
    }
    f(ii,0,m){
        cin>>b[ii];
    }
    ll i = 0 , j = 0;
    while (i <= n && j <= m ){
        if(i==n || j==m){
            break;
        }else if (a[i] <= b[j]){
           cout<<a[i]<<" ";
           i++;
        }else{
           cout<<b[j]<<" ";
           j++;
        }
    }
    while (i < n) {
        cout << a[i++] << " ";
    }
    while (j < m) {
        cout << b[j++] << " ";
    }
    
}
