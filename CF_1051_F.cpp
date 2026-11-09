#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct DSU{
    vi parent,size;
    DSU(ll n){
        parent.resize(n);
        size.assign(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    ll find(ll v){
        if(v==parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(ll a, ll b){
        a = find(a); b = find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};
struct BinaryLift{
    ll n,root,l,timer;
    vi tin,tout,depth,dist;
    vector<vector<ll>> up;
    BinaryLift(ll n, ll root, vector<vector<pair<ll,ll>>>&adj){
        this->n = n;
        this->root = root;
        timer = 0;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        dist.resize(n,0);
        up.assign(n,vector<ll>(l+1));
        dfs(root,root,0,0,adj);
    }
    void dfs(ll u, ll p, ll d, ll wsum, vector<vector<pair<ll,ll>>>&adj){
        tin[u] = timer++;
        depth[u] = d;
        dist[u] = wsum;
        up[u][0] = p;
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(auto [v,w] : adj[u]){
            if(v==p) continue;
            dfs(v,u,d+1,wsum+w,adj);
        }
        tout[u] = timer++;
    }
    bool isancestor(ll u, ll v){
        return (tin[u]<=tin[v] && tout[u]>=tout[v]);
    }
    ll get(ll u, ll v){
        if(isancestor(u,v)) return u;
        if(isancestor(v,u)) return v;
        for(ll i=l; i>=0; i--){
            if(!isancestor(up[u][i],v)) u = up[u][i];
        }
        return up[u][0];
    }
    ll getdist(ll u, ll v){
        ll lca = get(u,v);
        return dist[u]+dist[v]-2*dist[lca];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> edges;
        vector<vector<pair<ll,ll>>> adj(n+1);
        while(m--){
            ll u,v,w; cin >> u >> v >> w;
            u--; v--;
            edges.push_back({w,u,v});
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        sort(edges.begin(),edges.end());
        DSU dsu(n);
        vector<vector<pair<ll,ll>>> tree(n+1);
        set<ll> s;
        for(auto a : edges){
            ll w = a[0], u = a[1], v = a[2];
            if(dsu.unite(u, v)){
                tree[u].push_back({v,w});
                tree[v].push_back({u,w});
            }else{
                s.insert(u); s.insert(v);
            }
        }
        BinaryLift bl(n,0,tree);
        vector<vi> sdist;
        auto dijkstra = [&](ll u, ll n, vector<vector<pair<ll,ll>>>&adj)->vi{
            vi dist(n,1e18);
            dist[u] = 0;
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
            pq.push({0,u});
            while(!pq.empty()){
                auto [d,u] = pq.top(); pq.pop();
                if(dist[u]<d) continue;
                for(auto [v,w] : adj[u]){
                    if(dist[u]+w<dist[v]){
                        dist[v] = dist[u]+w;
                        pq.push({dist[v],v});
                    }
                }
            }
            return dist;
        };
        for(auto a : s){
            sdist.push_back(dijkstra(a,n,adj));
        }
        
        ll q; cin >> q;
        while(q--){
            ll u,v; cin >> u >> v;
            u--; v--;
            ll ans = bl.getdist(u, v);
            for(auto &a : sdist){
                ans = min(ans,a[u]+a[v]);
            }
            cout << ans << "\n";
        }
    }
}