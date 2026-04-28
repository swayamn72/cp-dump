#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct BinaryLift{
    ll n,root,l,timer;
    vector<ll> tin,tout,depth;
    vector<vector<ll>> up;
    BinaryLift(ll n, ll root, vector<vector<ll>>&adj){
        this->n = n;
        this->root = root;
        timer = 0;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<ll>(l+1));
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
    ll caseid = 1;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<ll>> adj(n);
        vector<ll> indegree(n,0);
        for(ll i=0; i<n; i++){
            ll m; cin >> m;
            for(ll j=0; j<m; j++){
                ll val; cin >> val; val--;
                indegree[val]++;
                adj[i].push_back(val);
            }
        }
        ll root = -1;
        for(ll i=0; i<n; i++){
            if(indegree[i]==0){
                root = i;
                break;
            }
        }
        BinaryLift bl(n,root,adj);
        ll q; cin >> q;
        cout << "Case " << caseid++ << ":" << "\n";
        while(q--){
            ll a,b; cin >> a >> b; a--; b--;
            cout << bl.get(a,b)+1 << "\n";
        }
    }
}