#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vector<vector<ll>> edges;
    vector<vector<ll>> adj(n);
    while(m--){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        edges.push_back({u,v,-w});
        adj[u].push_back(v);
    }
    vi dist(n,LLONG_MAX);
    dist[0] = 0;
    for(ll i=0; i<n-1; i++){
        bool flag = false;
        for(auto a : edges){
            ll u = a[0], v = a[1], w = a[2];
            if(dist[u]==LLONG_MAX) continue;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                flag = true;
            }
        }
        if(!flag) break;
    }
    vi affected;
    for(auto a : edges){
        ll u = a[0], v = a[1], w = a[2];
        if(dist[u]==LLONG_MAX) continue;
        if(dist[v]>dist[u]+w){
            affected.push_back(v);
        }
    }
    vector<bool> vis(n,false);
    queue<ll> q;
    for(auto a : affected){
        q.push(a);
        vis[a] = true;
    }
    while(!q.empty()){
        ll node = q.front(); q.pop();
        for(auto a : adj[node]){
                if(!vis[a]){
                vis[a] = true;
                q.push(a);
            }
        }
    }
    if(vis[n-1]) cout << -1;
    else cout << -dist[n-1];
}