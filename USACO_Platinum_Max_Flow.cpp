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
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        BinaryLift bl(n,0,adj);
        vi diff(n,0);
        while(k--){
            ll u,v; cin >> u >> v;
            u--; v--;
            ll lca = bl.get(u,v);
            diff[u]++; diff[v]++; diff[lca]--;
            if(lca!=0) diff[bl.up[lca][0]]--;
        }
        ll res = 0;
        auto dfs = [&](auto &&self, ll u, ll p)->ll{
            ll curr = diff[u];
            for(auto v : adj[u]){
                if(v==p) continue;
                curr += self(self,v,u);
            }
            res = max(res,curr);
            return curr;
        };
        dfs(dfs,0,-1);
        cout << res << "\n";
    }
}