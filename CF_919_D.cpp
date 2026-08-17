#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    string s; cin >> s;
    
    vector<vi> adj(n);
    while(m--){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    vector<vi> dp(n, vi(26,0));
    vi state(n,0); 
    bool cycle = false;
    // 0 - not visited  1 - curr  2 - done
    auto dfs = [&](auto &&self, ll u)->void{
        state[u] = 1;
        for(auto v : adj[u]){
            if(state[v]==1){
                cycle = true;
                return;
            }
            if(state[v]==0){
                self(self,v);
            }
            if(cycle) return;
            for(ll i=0; i<26; i++){
                dp[u][i] = max(dp[u][i],dp[v][i]);
            }
        }
        dp[u][s[u]-'a']++;
        state[u] = 2;
    };
    for(ll i=0; i<n; i++){
        if(state[i]==0){
            dfs(dfs,i);
            if(cycle){
                cout << -1;
                return 0;
            }
        }
    }
    ll res = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<26; j++){
            res = max(res,dp[i][j]);
        }
    }
    cout << res;
}