#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        vi size(n,0);
        auto dfs = [&](auto &&self, ll u, ll p) -> void{
            size[u] = 1;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
                size[u] += size[v];
            }
        };
        dfs(dfs,0,-1);
        ll res = n;
        for(ll i=0; i<n; i++){
            if(n-size[i]>=k) res += size[i];
            if(size[i]>=k) res += (n-size[i]);
        }
        cout << res << "\n";
    }
}