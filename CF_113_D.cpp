#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m,a,b; cin >> n >> m >> a >> b;
        a--; b--;
        vector<vi> adj(n);
        for(ll i=0; i<m; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<double> p(n);
        for(auto &x : p) cin >> x;

        // total states
        ll s = n*n;


        
    }
} 