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
        ll u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int diameter = 0;
    auto dfs = [&](auto &&self, ll u, ll p)-> int{
        int mx1 = 0, mx2 = 0;
        for(auto v : adj[u]){
            if(v==p) continue;
            int d = self(self,v,u) + 1;
            if(d>=mx1){
                mx2 = mx1;
                mx1 = d;
            }else if(d>mx2){
                mx2 = d;
            }
        }
        diameter = max(diameter,mx1+mx2);
        return mx1;
    };
    dfs(dfs,0,-1);
    cout << diameter;
}