#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vi color(n); for(auto &x : color) cin >> x;
        vector<vector<pair<ll,ll>>> adj(n);
        vi parent(n), edge(n,-1);
        ll sum = 0;
        for(ll i=0; i<n-1; i++){
            ll u,v,c; cin >> u >> v >> c;
            u--; v--;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
            if(color[u]!=color[v]) sum += c;
        }
        vector<map<ll,ll>> arr(n);
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            parent[u] = p;
            for(auto [v,c] : adj[u]){
                if(v==p) continue;
                arr[u][color[v]] += c;
                edge[v] = c;
                self(self,v,u);
            }
        };
        dfs(dfs,0,-1);
        while(q--){
            ll v,x; cin >> v >> x;
            v--;
            if(x==color[v]){
                cout << sum << "\n";
                continue;
            }
            ll old = color[v];
            sum += arr[v][old];
            sum -= arr[v][x];
            if(parent[v]!=-1){
                ll p = parent[v];
                ll e = edge[v];
                if(old!=color[p]) sum -= e;
                if(x!=color[p]) sum += e;
                arr[p][old] -= e;
                arr[p][x] += e;
            }
            color[v] = x;
            cout << sum << "\n";
        }
    }
} 