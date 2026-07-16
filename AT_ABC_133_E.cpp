#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin >> n >> k;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll res = k;
    bool flag = true;
    auto dfs = [&](auto &&self, ll u, ll p)->void{
        ll curr = k-2;
        if(u==0) curr++;
        for(auto v : adj[u]){
            if(v==p) continue;
            res = (res*curr)%mod;
            curr--;
            if(curr<0){
                flag = false;
            }
            self(self,v,u);
        }
    };    
    dfs(dfs,0,-1);
    if(!flag) cout << 0;
    else cout << res;
}