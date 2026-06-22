#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct LCA{
    ll n,l,timer;
    vi tin,tout;
    vector<vector<ll>> up;
    LCA(ll n, vector<vector<ll>>&adj){
        this->n = n;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<ll>(l+1,-1));
        dfs(0,0,adj);
    }
    void dfs(ll u, ll p, vector<vector<ll>>&adj){
        tin[u] = timer++;
        up[u][0] = p;
        for(ll i=1; i<=l; i++) up[u][i] = up[up[u][i-1]][i-1];
        for(auto a : adj[u]){
            dfs(a,u,adj);
        }
        tout[u] = timer++;
    }
    bool isancestor(ll u, ll v){
        return tin[u]<=tin[v] && tout[u]>=tout[v];
    }
    ll getancestor(ll u, ll v){
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
    vector<vector<ll>> adj(n);
    for(ll i=1; i<n; i++){
        ll x; cin >> x; x--;
        adj[x].push_back(i);
    }
    LCA lca(n,adj);
    while(q--){
        ll a,b; cin >> a >> b;
        a--; b--;
        cout << lca.getancestor(a,b)+1 << "\n";
    }
}