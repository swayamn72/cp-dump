#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<ll>> adj(n);
        for(ll i=1; i<=n-1; i++){
            ll u; cin >> u; u--;
            adj[u].push_back(i);
        }
        ll res = n;
        vi depth(n);
        auto dfs = [&](auto &&self, ll u, ll d)->ll{
            depth[u] = d;
            ll max1=0, max2=0;
            for(auto v : adj[u]){
                ll curmax = self(self,v,d+1);
                if(curmax>max1){
                    max2 = max1;
                    max1 = curmax;
                }else if(curmax>max2){
                    max2 = curmax;
                }
            }
            if(max2>0){
                res += (max2-d);
            }
            if(max1>d) return max1;
            return d;
        };
        dfs(dfs,0,1);
        // for(auto a : depth) cout << a << " ";
        // cout << "\n";
        cout << res << "\n";
    }
}