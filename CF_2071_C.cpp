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
        ll n,s,d; cin >> n >> s >> d;
        s--; d--;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }    
        vi depth(n);  
        auto dfs = [&](auto &&self, ll u, ll p, ll de)->void{
            depth[u] = de;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,de+1);
            }
        };
        dfs(dfs,d,-1,0);
        vector<vi> v;
        for(ll i=0; i<n; i++){
            v.push_back({depth[i],i});
        }
        sort(v.rbegin(),v.rend());
        for(auto a : v){
            cout << a[1]+1 << " ";
        }
        cout << "\n";
    }
}