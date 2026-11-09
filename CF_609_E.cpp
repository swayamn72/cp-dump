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
    ll n,l;
    vi depth;
    vector<vi> up,mx;
    BinaryLift(ll n, ll root, vector<vector<pair<ll,ll>>>&adj){
        this->n = n;
        l = ceil(log2(n));
        if(l<2)l=2;
        depth.resize(n);
        up.assign(n,vi(l+1));
        mx.assign(n,vi(l+1,0));
        dfs(root,root,0,0,adj);
    }
    void dfs(ll u, ll p, ll d, ll w, vector<vector<pair<ll,ll>>> &adj){
        depth[u] = d;
        up[u][0] = p;
        mx[u][0] = w;
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
            mx[u][i] = max(mx[u][i-1],mx[up[u][i-1]][i-1]);
        }
        for(auto &[v,w] : adj[u]){
            if(v==p) continue;
            dfs(v,u,d+1,w,adj);
        }
    }
    ll getmax(ll u, ll v){
        ll res = 0;
        if(depth[u]<depth[v]) swap(u,v);
        for(ll i=l; i>=0; i--){
            if(depth[u]-(1LL<<i)>=depth[v]){
                res = max(res,mx[u][i]);
                u = up[u][i];
            }
        }
        if(u==v) return res;
        for(ll i=l; i>=0; i--){
            if(up[u][i]!=up[v][i]){
                res = max({res,mx[u][i],mx[v][i]});
                u = up[u][i]; v = up[v][i];
            }
        }
        res = max({res,mx[u][0],mx[v][0]});
        return res;
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
        vector<vi> edges;
        for(ll i=0; i<m; i++){
            ll u,v,w; cin >> u >> v >> w;
            u--; v--;
            edges.push_back({u,v,w,i});
        }
        vector<vi> sortededges = edges;
        sort(sortededges.begin(),sortededges.end(),[](const vi &a, const vi &b){
            return a[2]<b[2];
        });
        DSU dsu(n);
        vector<vector<pair<ll,ll>>> adj(n);
        ll mstw = 0;
        for(auto &a : sortededges){
            ll u = a[0], v = a[1], w = a[2];
            if(dsu.unite(u, v)){
                mstw += w;
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
        }
        BinaryLift bl(n,0,adj);
        vi res(m);
        for(auto &a : edges){
            ll u = a[0], v = a[1], w = a[2], id = a[3];
            ll maxv = bl.getmax(u, v);
            res[id] = mstw + w - maxv;
        }
        for(auto a : res) cout << a << "\n"; 
    }
}