#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<vi> adj(n);
    while(m--){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    vi dp(n,-1);

    auto dfs = [&](auto &&self, ll u){
        if(dp[u]!=-1) return dp[u];
        ll ans = 0;
        for(auto v : adj[u]){
            ans = max(ans,1+self(self,v));
        }
        return dp[u] = ans;
    };
    ll res = 0;
    for(ll i=0; i<n; i++) res = max(res,dfs(dfs,i));
    cout << res;
}