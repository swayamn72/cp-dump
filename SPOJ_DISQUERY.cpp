#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll INF = 1e9;
struct LCA{
    ll n,l,timer;
    vi tin,tout,depth;
    vector<vector<ll>> up,mn,mx;
    LCA(ll n, ll root, vector<vector<pair<ll,ll>>> &adj){
        this->n = n;
        timer = 0;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.resize(n, vector<ll>(l+1));
        mn.assign(n, vector<ll>(l+1,INF));
        mx.assign(n, vector<ll>(l+1,-INF));
        dfs(root,root,0,adj);
    }
    void dfs(ll node, ll p, ll w, vector<vector<pair<ll,ll>>> &adj){
        tin[node] = timer++;
        up[node][0] = p;
        if(node!=p){
            mx[node][0] = w;
            mn[node][0] = w;
        }
        for(ll i=1; i<=l; i++){
            up[node][i] = up[up[node][i-1]][i-1];
            mn[node][i] = min(mn[node][i-1], mn[up[node][i-1]][i-1]);
            mx[node][i] = max(mx[node][i-1], mx[up[node][i-1]][i-1]);
        }
        for(auto edge : adj[node]){
            auto [w,a] = edge;
            if(a==p) continue;
            depth[a] = depth[node]+1;
            dfs(a,node,w,adj);
        }
        tout[node] = timer++;
    }
    bool ancestor(ll u, ll v){
        return tin[u]<=tin[v] && tout[u]>=tout[v];
    }
    ll lcancestor(ll u, ll v){
        if(ancestor(u,v)) return u;
        if(ancestor(v,u)) return v;
        for(ll i=l; i>=0; i--){
            if(!ancestor(up[u][i],v)) u = up[u][i];
        }
        return up[u][0];
    }
    pair<ll,ll> query(ll u, ll v){
        ll lcanode = lcancestor(u,v);
        ll minv = INF, maxv = -INF;
        auto lift = [&](ll curr, ll dist){
            for(ll i=l; i>=0; i--){
                ll jumpsize = (1LL<<i);
                if(jumpsize<=dist){
                    minv = min(minv,mn[curr][i]);
                    maxv = max(maxv,mx[curr][i]);
                    curr = up[curr][i];
                    dist -= jumpsize;
                }
            }
        };
        lift(u,depth[u]-depth[lcanode]);
        lift(v,depth[v]-depth[lcanode]);
        return {minv,maxv};
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    LCA lca(n,0,adj);
    ll q; cin >> q;
    while(q--){
        ll u,v; cin >> u >> v;
        u--; v--;
        auto ans = lca.query(u,v);
        cout << ans.first << " " << ans.second << "\n";
    }
}