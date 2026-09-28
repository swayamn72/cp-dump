#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll res = 0;
        vi g(n); 
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            ll sum = 0;
            ll gcdv = b[u];
            g[u] = a[u];
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
                sum += a[v];
                if(g[v]!=b[v]) gcdv = gcd(gcdv,g[v]);
            }
            gcdv = gcd(gcdv,sum);
            g[u] = gcdv;
            ll maxv = a[u] + ((b[u]-1-a[u])/gcdv)*gcdv;
            res += maxv;
        };
        dfs(dfs,0,-1);
        cout << res << "\n";
    }
}