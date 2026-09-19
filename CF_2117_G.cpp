#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
ll inf = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<pair<ll,ll>>> adj(n);
        vector<vi> edges;
        for(ll i=0; i<m; i++){
            ll u,v,w; cin >> u >> v >> w;
            u--; v--;
            edges.push_back({u,v,w});
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }        
        auto dijkstra = [&](ll start, ll end)->vi{
            vi dist(n,inf);
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
            dist[start] = 0;
            pq.push({0,start});
            while(!pq.empty()){
                auto [d,u] = pq.top();
                pq.pop();
                if(d>dist[u]) continue;
                for(auto [w,v] : adj[u]){
                    ll newd = max(d,w);
                    if(newd<dist[v]){
                        dist[v] = newd;
                        pq.push({newd,v});
                    }
                }
            }
            return dist;
        };
        vi dist0 = dijkstra(0,n-1);
        vi distn = dijkstra(n-1,0);
        ll res = inf;
        for(auto a : edges){
            ll u = a[0], v = a[1], w = a[2];
            res = min(res,w+max({dist0[u],distn[v],w}));
            res = min(res,w+max({dist0[v],distn[u],w}));
        }
        cout << res << "\n";
    }
} 