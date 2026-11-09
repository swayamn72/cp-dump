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
    ll query(ll u, ll v, ll c){
        ll lca = get(u,v);
        ll dist1 = depth[u]-depth[lca];
        ll dist2 = depth[v]-depth[lca];
        if(c>=dist1+dist2) return v;
        if(c<=dist1){
            ll curr = u;
            ll k = c;
            for(ll l=20; l>=0; l--){
                if((1<<l)<=k){
                    k -= (1LL<<l);
                    curr = up[curr][l];
                }
            }
            return curr;
        }
        ll dist = c-dist1;
        dist = dist2-dist;
        ll curr = v;
        for(ll l=20; l>=0; l--){
            if((1<<l)<=dist){
                dist -= (1LL<<l);
                curr = up[curr][l];
            }
        }
        return curr;
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
        ll n; cin >> n;
        if(n==1){
            ll q; cin >> q;
            while(q--){
                ll a,b,c; cin >> a >> b >> c;
                cout << 1 << "\n";
            }
            continue;
        }
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        BinaryLift bl(n,0,adj);
        ll q; cin >> q;
        while(q--){
            ll u,v,c; cin >> u >> v >> c; u--; v--;
            cout << bl.query(u,v,c)+1 << "\n";
        }
    }
}