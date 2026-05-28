#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vector<vector<ll>> adj(n);
    while(m--){
        ll x,y; cin >> x >> y; 
        x--; y--;
        adj[x].push_back(y);
    }
    vector<ll> dp(n,-1);
    auto dfs = [&](auto &&self, ll u) -> ll{
        if(dp[u]!=-1) return dp[u];
        dp[u] = 0;
        for(auto a : adj[u]){
            dp[u] = max(dp[u], 1 + self(self,a));
        }
        return dp[u];
    };
    ll res = 0;
    for(ll i=0; i<n; i++){
        res = max(res, dfs(dfs,i));
    }
    cout << res;
}