#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        for(ll i=0; i<n; i++){
            ll k; cin >> k;
            for(ll j=0; j<k; j++){
                ll v; cin >> v;
                v--;
                adj[i].push_back(v);
            }
        }
        vi state(n,0); // 0-notvisited 1-curr 2-visited
        vi dp(n,-1);
        bool cycle = false;
        auto dfs = [&](auto &&self, ll u)->void{
            if(cycle) return;
            state[u] = 1;
            ll passes = 1;
            for(auto v : adj[u]){
                if(state[v]==1){
                    cycle = true;
                    return;
                }
                if(state[v]==0) self(self,v);
                if(cycle) return;
                ll reqpasses = dp[v] + (v>u ? 1 : 0);
                passes = max(passes,reqpasses);
            }
            dp[u] = passes;
            state[u] = 2;
        };
        for(ll i=0; i<n; i++){
            if(!state[i]) dfs(dfs,i);
        }
        if(cycle){
            cout << -1 << "\n";
            continue;
        }
        cout << *max_element(dp.begin(),dp.end()) << "\n";
    }
}