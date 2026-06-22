#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct Tree{
    ll n,l;
    vi depth, size;
    vector<vector<ll>> up;
    Tree(ll n, vector<vector<ll>>&adj){
        this->n = n;
        l = 20;
        depth.resize(n,0);
        size.resize(n,0);
        up.resize(n,vector<ll>(l+1,0));
        dfs(0,0,adj);
    }
    void dfs(ll u, ll p, vector<vector<ll>>&adj){
        up[u][0] = p;
        size[u] = 1;
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(auto a : adj[u]){
            if(a==p) continue;
            depth[a] = depth[u]+1;
            dfs(a,u,adj);
            size[u] += size[a];
        }
    }
    ll lift(ll node, ll k){
        for(ll i=l; i>=0; i--){
            ll dist = (1LL<<i);
            if(dist<=k){
                k-=dist;\
                node = up[node][i];
            } 
        }
        return node;
    }
    ll ancestor(ll u, ll v){
        if(depth[u]<depth[v]) swap(u,v);
        u = lift(u,depth[u]-depth[v]);
        if(u==v) return u;
        for(ll i=l; i>=0; i--){
            if(up[u][i]!=up[v][i]){
                u = up[u][i]; v = up[v][i];
            }
        }
        return up[u][0];
    }
    ll getdist(ll u, ll v){
        ll lcanode = ancestor(u,v);
        return depth[u] + depth[v] - 2*depth[lcanode];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Tree tree(n,adj);
    ll m; cin >> m;
    while(m--){
        ll u,v; cin >> u >> v; u--; v--;
        if(u==v){
            cout << n << "\n";
            continue;
        }
        ll dist = tree.getdist(u,v);
        if(dist%2){
            cout << 0 << "\n";
            continue;
        }
        ll half = dist/2;
        if(tree.depth[u]<tree.depth[v]) swap(u,v);
        ll midpoint = tree.lift(u,half);
        if(tree.depth[u]==tree.depth[v]){
            ll childu = tree.lift(u,half-1);
            ll childv = tree.lift(v,half-1);
            cout << n - tree.size[childu] - tree.size[childv] << "\n";
        }else{
            ll childu = tree.lift(u,half-1);
            cout << tree.size[midpoint] - tree.size[childu] << "\n";
        }
    }
}