#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi c(n); for(auto &x : c) cin >> x;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        vector<set<ll>> arr(n);
        vi res(n);
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            arr[u].insert(c[u]);
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
                if(arr[u].size()<arr[v].size()) swap(arr[u],arr[v]);
                for(auto a : arr[v]){
                    arr[u].insert(a);
                }
                
            }
            res[u] = arr[u].size();
        };
        dfs(dfs,0,-1);
        for(auto a : res) cout << a << " ";
    }
}