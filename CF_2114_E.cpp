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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll root = 0;
        vector<ll> maxv(n,0), minv(n,0);
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            maxv[u] = arr[u], minv[u] = arr[u];
            if(p!=-1){
                maxv[u] = max(maxv[u],arr[u]-minv[p]);
                minv[u] = min(minv[u],arr[u]-maxv[p]);
            }
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
        };
        dfs(dfs,0,-1);
        for(auto a : maxv) cout << a << " ";
        cout << "\n";
    }
}