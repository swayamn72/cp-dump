#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi c(n); for(auto &x : c) {cin >> x; x--;}
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        ll res = 0;       
        vector<map<ll,ll>> dp(n);
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
                if(dp[v].size()>dp[u].size()) swap(dp[u],dp[v]);
                for(auto a : dp[v]){
                    if(a.first!=c[u] && dp[u].count(a.first)){
                        res += dp[u][a.first] * a.second;
                    }
                    dp[u][a.first] += a.second;
                }
            }
            ll color = c[u];
            if(dp[u].count(c[u])){
                res += dp[u][c[u]];
            }
            dp[u][c[u]] = 1;
        };
        dfs(dfs,0,-1);
        cout << res << "\n";
    }
}