#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    if(n==1){
        cout << 0;
        return 0;
    }
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto &&self, ll u, ll p)->double{
        ll children = 0;
        double curr = 0.0;
        for(auto v : adj[u]){
            if(v==p) continue;
            curr += (self(self,v,u));
            curr += 1.0;
            children++;
        }
        if(children==0) return 0.0;
        return (curr/children);
    };
    double res = dfs(dfs,0,-1);
    cout << fixed << setprecision(6) << res;
}