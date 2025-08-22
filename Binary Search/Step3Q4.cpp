#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using mpi = map<int,int>;
using mpl = map<ll,ll>;
using mpd = map<db,db>;

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

#define input(type, ...) type __VA_ARGS__; cin >> __VA_ARGS__;
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
#define r_all(n) n.rbegin() , n.rend()
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define unique_sort(vec) sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
#define FILL(vec, value) fill(vec.begin(), vec.end(), value)
#define IOTA(vec, start) iota(all(vec), start)
#define endl "\n"
#define INF 1e18
const int MOD = 1e9 + 7;

ll pow(ll a , ll b){
    ll res = 1;
    while(b>0){
        if(b%2==1) res*=a;
        a *= a; b /= 2;
    }
    return res;
}

ll powerWithModulo(ll base, ll exponent, int mod) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

class DSU{
    vector<int> rank , parent , size;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i <= n ; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void UnionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int n, m, d;
vector<tuple<int, int, int>> edges;
vector<vector<pair<int, int>>> adj;

bool bfs(int max_cost, vector<int> &parent){
    vector<int> dist(n + 1, 1e9);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    parent[1] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] >= d) continue;
        for (auto &[v, c] : adj[u]){
            if (c <= max_cost && dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return dist[n] <= d;
}

vector<int> recover_path(vector<int> &parent) {
    vector<int> path;
    int cur = n;
    while (cur != -1){
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    return path;
}

void solve(){
    cin>>n>>m>>d;
    edges.resize(m);
    int a, b, c;
    f(i,0,m){
        cin>>a>>b>>c;
        edges[i] = {a, b, c};
    }
    int l = 0, r = 1e9, ans = -1;
    vector<int> best_path;
    while(l <= r){
        int mid = (l + r) / 2;
        adj.assign(n + 1, {});
        for (auto &[u, v, cost] : edges){
            if (cost <= mid) {
                adj[u].push_back({v, cost});
            }
        }
        vector<int> parent(n + 1, -1);
        if (bfs(mid, parent)){
            ans = mid;
            best_path = recover_path(parent);
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    if (ans == -1){
        cout << "-1\n";
    }else{
        cout<<best_path.size() - 1<<endl;;
        for(int node : best_path)
            cout<<node<<" ";
        cout<<endl;;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll t=1 ; //cin>>t;
    while(t--){
	    solve();
    }
}