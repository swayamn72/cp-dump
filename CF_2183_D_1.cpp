#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi depth(n);
        ll maxd = 0;
        ll res1 = adj[0].size();
        auto dfs = [&](auto &&self, ll u, ll p, ll d)->void{
            depth[u] = d;
            maxd = max(maxd,d);
            ll size = adj[u].size();
            res1 = max(res1,size-1);
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,d+1);
            }
        };
        dfs(dfs,0,0,0);
        maxd++;
        // for(auto a : depth) cout << a << " ";
        // cout << "\n";
        vi arr(maxd,0);
        for(auto a : depth){
            arr[a]++;
        }
        ll res2 = *max_element(arr.begin(),arr.end());
        cout << max(res1+1,res2) << "\n";
        // // for(auto a : arr) cout << a << " ";
        // // cout << "\n";
        // ll res = 0;
        // for(ll i=0; i<maxd; i++){
        //     if(arr[i]==0) continue;
        //     ll buffer = arr[i];
        //     res += buffer;
        //     for(ll j=i+2; j<maxd; j++){
        //         arr[j] -= min(buffer,arr[j]);
        //     }
        // }
        // cout << res << "\n";
        // // cout << "\n";
        // // map<ll,ll> mp;
        // // ll maxodd = 0, maxeven = 0;
        // // for(auto a : depth) mp[a]++;
        // // for(auto a : mp){
        //     // cout << a.first << " " << a.second << "   ";

        // //     if(a.first%2==1) maxodd = max(maxodd,a.second);
        // //     else maxeven = max(maxeven,a.second);
        // // }
        // // cout << "\n";
        // // cout << maxodd + maxeven << "\n";
    }
}