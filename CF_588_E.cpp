#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
vi merge(vi &a, vi &b){
    vi res;
    for(auto x : a) res.push_back(x);
    for(auto x : b) res.push_back(x);
    sort(res.begin(),res.end());
    ll sz = min(10,(int)res.size());
    res.resize(sz);
    return res;
}
struct BinaryLift{
    ll n,root,l,timer;
    vi tin,tout,depth;
    vector<vector<ll>> up;
    vector<vector<vi>> top;
    BinaryLift(ll n, ll root, vector<vector<ll>>&adj, vector<vi>&arr){
        this->n = n;
        this->root = root;
        timer = 0;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n,vector<ll>(l+1));
        top.assign(n,vector<vi>(l+1));
        dfs(root,root,0,adj,arr);
    }
    void dfs(ll u, ll p, ll d, vector<vector<ll>>&adj, vector<vi>&arr){
        tin[u] = timer++;
        depth[u] = d;
        up[u][0] = p;
        for(ll i=0; i<min(10LL,(ll)arr[u].size()); i++){
            top[u][0].push_back(arr[u][i]);
        }
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
            top[u][i] = merge(top[u][i-1],top[up[u][i-1]][i-1]);
        }
        for(auto v : adj[u]){
            if(v==p) continue;
            dfs(v,u,d+1,adj,arr);
        }
        tout[u] = timer++;
    }
    vi query(ll u, ll v, ll a){
        vi res;
        if(depth[u]<depth[v]) swap(u,v);
        for(ll i=l; i>=0; i--){
            if(depth[u]-(1LL<<i)>=depth[v]){
                res = merge(res,top[u][i]);
                u = up[u][i];
            }
        }
        if(u==v) res = merge(res,top[u][0]);
        else{
            for(ll i=l; i>=0; i--){
                if(up[u][i]!=up[v][i]){
                    res = merge(res,top[u][i]);
                    res = merge(res,top[v][i]);
                    u = up[u][i];
                    v = up[v][i];
                }
            }
            res = merge(res,top[u][0]);
            res = merge(res,top[v][0]);
            res = merge(res,top[up[u][0]][0]);
        }
        while(res.size()>a) res.pop_back();
        return res;
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
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m,q; cin >> n >> m >> q;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vi> arr(n);
        for(ll i=1; i<=m; i++){
            ll c; cin >> c; c--;
            arr[c].push_back(i);
        }
        BinaryLift bl(n,0,adj,arr);
        while(q--){
            ll u,v,a; cin >> u >> v >> a; u--; v--;
            vi ans = bl.query(u, v, a);
            cout << ans.size() << " ";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}