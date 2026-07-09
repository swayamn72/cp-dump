#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll res = 0;
    vector<bool> matched(n,false);
    auto dfs = [&](auto &&self, ll u, ll p)->void{
        for(auto v : adj[u]){
            if(v==p) continue;
            self(self,v,u);
        }
        if(u==0) return;
        if(!matched[u]&&!matched[p]){
            res++;
            matched[u] = true;
            matched[p] = true;
        }
    };
    dfs(dfs,0,-1);
    cout << res;
}