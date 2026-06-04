#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll v; cin >> v; v--; 
        adj[i+1].push_back(v);
        adj[v].push_back(i+1);
    }
    vi depth(n);
    auto dfs = [&](auto &&self, ll u, ll p)-> void{
        depth[u] = 0;
        for(auto v : adj[u]){
            if(v==p) continue;
            self(self,v,u);
            depth[u] += depth[v]+1;
        }
    };
    dfs(dfs,0,-1);
    for(auto a : depth) cout << a << " ";
}