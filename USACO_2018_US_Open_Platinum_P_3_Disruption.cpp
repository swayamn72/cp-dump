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
    BinaryLift(ll n, ll root, vector<vector<pair<ll,ll>>>&adj){
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
    void dfs(ll u, ll p, ll d, vector<vector<pair<ll,ll>>>&adj){
        tin[u] = timer++;
        depth[u] = d;
        up[u][0] = p;
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(auto [v,b] : adj[u]){
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
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<pair<ll,ll>>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        BinaryLift bl(n,0,adj);
        vector<vi> add(n), rem(n);
        for(ll i=0; i<m; i++){
            ll p,q,r; cin >> p >> q >> r;
            p--; q--;
            ll lca = bl.get(p, q);
            if(p!=lca){
                add[p].push_back(r);
                rem[lca].push_back(r);
            }
            if(q!=lca){
                add[q].push_back(r);
                rem[lca].push_back(r);
            }
        }
        vector<multiset<ll>> s(n);
        vi res(n-1,-1);
        auto dfs = [&](auto &&self, ll u, ll p, ll edgeidx)->void{
            for(auto &[v,idx] : adj[u]){
                if(v==p) continue;
                self(self,v,u,idx);
                if(s[v].size()<s[u].size()){
                    swap(s[u],s[v]);
                }
                for(auto w : s[v]) s[u].insert(w);
            }
            for(auto w : add[u]){
                s[u].insert(w);
            }
            for(auto w : rem[u]){
                s[u].erase(s[u].find(w));
            }
            if(edgeidx!=-1){
                if(!s[u].empty()){
                    res[edgeidx] = *s[u].begin();
                }
            }
        };
        dfs(dfs,0,-1,-1);
        for(auto a : res) cout << a << "\n";
    }
}