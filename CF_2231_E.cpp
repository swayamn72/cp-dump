#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct BinaryLift{
    ll timer, n, l;
    vi tin, tout, depth;
    vector<vector<ll>> up;
    BinaryLift(ll n, vector<vector<ll>> &adj, ll root){
        this->n = n;
        l = ceil(log2(n));
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n,vector<ll>(l+1));
        dfs(root,root,0,adj);
    }
    void dfs(ll u, ll p, ll d, vector<vector<ll>>&adj){
        depth[u] = d;
        up[u][0] = p;
        tin[u] = timer++;
        for(ll i=1; i<=l; i++){
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
    ll get(ll u, ll v){
        if(isancestor(u,v)) return u;
        if(isancestor(v,u)) return v;
        for(ll i=l; i>=0; i--){
            if(!isancestor(up[u][i],v)) u = up[u][i];
        }
        return up[u][0];
    }
    ll getdepth(ll u){
        return depth[u];
    }
};
void dfsdown(ll u, ll p, vector<vector<ll>>&adj, vector<vector<ll>>&downarr,ll n){
    downarr[u][0] = 1;
    for(auto v : adj[u]){
        if(v==p) continue;
        dfsdown(v,u,adj,downarr,n);
        for(ll i=1; i<=n; i++){
            downarr[u][i] += downarr[v][i-1];
        }
    }
}
void dfsup(ll u, ll p, vector<vector<ll>>&adj, vector<vector<ll>>&downarr, vector<vector<ll>>&uparr, ll n){
    for(auto v : adj[u]){
        if(v==p) continue;
        uparr[v][1]++;
        for(ll i=1; i<=n; i++){
            if(i<n) uparr[v][i+1] += uparr[u][i];
            
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,d; cin >> n >> d;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        BinaryLift bl(n,adj,0);
        ll res = 0;
        for(ll i=0; i<n; i++) for(ll j=i+1; j<n; j++){
            ll u = i, v = j;
            ll lca = bl.get(u,v);
            ll dist = bl.getdepth(u) + bl.getdepth(v) - 2*bl.getdepth(lca);
            if(dist==d-1){
                res += (d-2);
            }
        }
    }
}