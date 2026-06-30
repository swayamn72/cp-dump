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
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vector<ll>> adj(n);
        vi size(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        auto dfs = [&](auto &&self, ll u, ll p)->ll{
            size[u] = 1;
            for(auto v : adj[u]){
                if(v==p) continue;
                size[u] += self(self,v,u);
            }
            return size[u];
        };
        dfs(dfs,0,0);
        ll res = 0;
        for(ll i=0; i<n; i++){
            ll root = sqrt(arr[i]);
            if(root*root != arr[i]) continue;
            ll sum1 = 0, sum2 = 0, sum3 = 0;
            for(auto v : adj[i]){
                ll subtree = size[v];
                if(size[v]>size[i]){
                    subtree = n - size[i];
                }
                sum3 += (subtree)*sum2;
                sum2 += (subtree)*sum1;
                sum1 += subtree;
            }
            res += (sum2+sum3);
        }
        cout << res << "\n";
    }
}