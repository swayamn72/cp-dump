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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr){
            cin >> x; if(x==0) x = -1;
        } 
        vector<vi> adj(n); 
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi res(n);
        vi dp(n);
        auto dfs = [&](auto &&self, ll u, ll p)->ll{
            ll val = arr[u];
            for(auto v : adj[u]){
                if(v==p) continue;
                val += max(0LL,self(self,v,u));
            }
            dp[u] = val;
            return val;
        };
        dfs(dfs,0,-1);
        auto dfs2 = [&](auto &&self, ll u, ll p)->void{
            res[u] = dp[u];
            if(p!=-1){
                ll pdp = res[p];
                pdp -= max(0LL,dp[u]);
                res[u] += max(0LL,pdp);
            }
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
        };
        dfs2(dfs2,0,-1);

        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}