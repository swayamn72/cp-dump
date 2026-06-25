#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct LCA{
    ll n,l,timer;
    vi tin,tout,depth;
    vector<vector<ll>> up;
    LCA(ll n, vector<vector<ll>>&adj){
        this->n = n;
        l = ceil(log2(n));
        timer = 0;
        depth.resize(n);
        tin.resize(n);
        tout.resize(n);
        up.resize(n, vector<ll>(l+1));
        dfs(0,0,1,adj);
    }
    void dfs(ll u, ll p, ll d, vector<vector<ll>>&adj){
        depth[u] = d;
        tin[u] = timer++;
        up[u][0] = p;
        for(ll i=1;i<=l;i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(auto v : adj[u]){
            if(v==p) continue;
            dfs(v,u,d+1,adj);
        }
        tout[u] = timer++;
    }
    bool isancestor(ll u, ll v){
        return tin[u]<=tin[v] && tout[u]>=tout[v];
    }
    ll lca(ll u, ll v){
        if(isancestor(u,v)) return u;
        if(isancestor(v,u)) return v;
        for(ll i=l; i>=0; i--){
            if(!isancestor(up[u][i],v)){
                u = up[u][i];
            }
        }
        return up[u][0];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,q; cin >> n >> q;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca(n,adj);
    while(q--){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        ll node1 = lca.lca(a,c);
        ll node2 = lca.lca(a,d);
        ll node3 = lca.lca(b,c);
        ll node4 = lca.lca(b,d);
        vector<pair<ll,ll>> arr(4);
        arr[0] = {lca.depth[node1],node1};
        arr[1] = {lca.depth[node2],node2};
        arr[2] = {lca.depth[node3],node3};
        arr[3] = {lca.depth[node4],node4};
        sort(arr.rbegin(),arr.rend());
        ll u = arr[0].second;
        ll v = arr[1].second;
        ll lcaab = lca.lca(a,b);
        ll lcacd = lca.lca(c,d);
        if(lca.depth[u]>=max(lca.depth[lcaab],lca.depth[lcacd])){
            ll lcanode = lca.lca(u,v);
            cout << lca.depth[u] + lca.depth[v] - 2*lca.depth[lcanode] + 1 << "\n";
        }else{
            cout << 0 << "\n";
        }
    }
}