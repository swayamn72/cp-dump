#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct BinaryLift{
    ll n,root,l,timer;
    vi tin,tout,depth;
    vector<vector<ll>> up;
    BinaryLift(ll n, ll root, vector<vector<ll>>&adj){
        this->n = n;
        this->root = root;
        timer = 0;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n,vector<ll>(l+1));
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
            if(v==p) continue;
            dfs(v,u,d+1,adj);
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        

        vi parent(n), depth(n);
        auto dfs = [&](auto &&self, ll u, ll p, ll d)->void{
            parent[u] = p; depth[u] = d;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,d+1);
            }
        };
        dfs(dfs,0,-1,0);
        ll last = n-1;
        vi v;
        while(parent[last]!=0) {v.push_back(last); last = parent[last];}

        ll secondroot = last;
        // cout << secondroot << "\n";
        set<ll> s;
        auto dfs2 = [&](auto &&self, ll u, ll p)->void{
            s.insert(u);
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
        };
        dfs2(dfs2,secondroot,0);
        ll res = depth[n-1];

        BinaryLift bl(n,0,adj);
        while(m--){
            ll x; cin >> x; x--;
            if(!s.count(x)) continue;
            ll lca = bl.get(x,n-1);
            ll newd = 1 + depth[x] + depth[n-1] - 2*depth[lca];
            res = max(res,newd);
        }
        cout << res << "\n";
    }
}