#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<pair<ll,ll>> edges;
        while(m--){
            ll u,v; cin >> u >> v;
            edges.push_back({u,v});
        }   
        ll w; cin >> w;
        vector<ll> holidays(n);
        for(auto &x : holidays) cin >> x;
        vector<vector<ll>> adj(n*w+1);
        for(auto [u,v] : edges){
            for(ll i=1; i<w; i++){
                adj[u*i].push_back(v*(i+1));
                adj[v*i].push_back(u*(i+1));
            }
            adj[u*w].push_back(v);
            adj[v*w].push_back(u);
        }
        

    }
}