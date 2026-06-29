#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi size(n,0);
    auto dfs = [&](auto &&self, ll u, ll p)->ll{
        size[u] = 1;
        for(auto v : adj[u]){
            if(v==p) continue;
            ll subsize = self(self,v,u);
            size[u] += subsize;
        }
        return size[u];
    };
    dfs(dfs,0,0);
    ll centroid = -1;
    ll maxv = n/2;
    ll u = 0;
    ll p = -1;
    while(centroid==-1){
        bool flag = true;
        ll heavy = -1;
        for(auto v : adj[u]){
            if(v==p) continue;
            if(size[v]>maxv){
                flag = false;
            }
            if(heavy == -1 || size[v]>size[heavy]){
                heavy = v;
            }
        }
        if(flag){
            centroid = u;
            break;
        }
        p = u;
        u = heavy;
    }
    cout << centroid+1;
}