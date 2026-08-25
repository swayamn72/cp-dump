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
        ll n; cin >> n;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll x; cin >> x; x--;
            adj[x].push_back(i+1);
        }        
        vi size(n);
        auto dfs = [&](auto &&self, ll u)->ll{
            ll sz = 0;
            for(auto v : adj[u]){
                sz += self(self,v);
            }
            return size[u] = sz+1;
        };
        dfs(dfs,0);
        // for(auto a : size) cout << a << " ";
        vector<double> res(n);
        res[0] = 1.0;
        auto dfs2 = [&](auto &&self, ll u)->void{
            for(auto v : adj[u]){
                res[v] = res[u] + 1.0 + (size[u]-1-size[v])/2.0;
                self(self,v);
            }
        };
        dfs2(dfs2,0);
        for(auto a : res) cout << fixed << setprecision(6) << a << " ";
    }
} 