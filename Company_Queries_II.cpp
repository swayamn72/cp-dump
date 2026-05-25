#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct BinaryLift{
    ll n, timer, l;
    vi depth, tin, tout;
    vector<vector<ll>> up;
    BinaryLift(ll n, vector<vector<ll>>&adj, ll root){
        l = ceil(log2(n));
        timer = 0;
        this->n = n;
        depth.resize(n);
        tin.resize(n);
        tout.resize(n);
        up.resize(n,vector<ll>(l+1));
        dfs(root,root,0,adj);
    }
    void dfs(ll u, ll p, ll d, vector<vector<ll>>&adj){
        tin[u] = timer++;
        depth[u] = d;
        up[u][0] = p;
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(auto v : adj[u]){
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
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,q; cin >> n >> q;
    vi parent(n); 
    vector<vector<ll>> adj(n);
    for(ll i=1; i<=n-1; i++){
        ll u; cin >> u; u--;
        parent[i] = u;
        adj[u].push_back(i);
    }
    ll root = 0;
    BinaryLift bl(n,adj,root);
    while(q--){
        ll a,b; cin >> a >> b;
        a--; b--;
        cout << bl.get(a,b) + 1 << "\n";
    }
}