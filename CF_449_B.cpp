#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m,k; cin >> n >> m >> k;
    vector<vector<vector<ll>>> adj(n);
    vector<ll> dist(n,LLONG_MAX);
    dist[0] = 0;
    while(m--){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({w,v,0});
        adj[v].push_back({w,u,0});
    }
    ll res = k;
    while(k--){
        ll s,y; cin >> s >> y;
        s--;
        adj[0].push_back({y,s,1});
        adj[s].push_back({y,0,1});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0,0});

    

    vi arr(n,0);

    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();
        ll d = curr[0], u = curr[1];
        if(d>dist[u]) continue;
        for(auto a : adj[u]){
            ll w = a[0], v = a[1], type = a[2];    
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
                arr[v]=type;
            }else if(dist[u]+w==dist[v] && type==0){
                arr[v] = 0;
            }
        }
    }
    for(ll i=1; i<n; i++) if(arr[i]) res--;
    cout << res;
}