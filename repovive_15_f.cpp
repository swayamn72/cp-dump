#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
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
        if(n==1){
            cout << 1 << "\n";
            continue;
        }
        vector<bool> vis(n,false);  
        vi parent(n,-1);
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            parent[u] = p;
            vis[u] = true;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
        };
        dfs(dfs,0,-1);
        vi path;
        ll curr = n-1;
        while(curr!=0){
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(0);
        reverse(path.begin(),path.end());
        // for(auto a : path) cout << a << " ";
        // cout << "\n";

        vector<bool> inpath(n,false);
        for(auto a : path) inpath[a] = true;

        vi size(n,1);
        auto dfs2 = [&](auto &&self, ll u, ll p)->ll{
            ll size = 1;
            for(auto v : adj[u]){
                if(v==p || inpath[v]) continue;
                size += self(self,v,u);
            }
            return size;
        };
        for(auto a : path){
            ll val = dfs2(dfs2,a,-1);
            size[a] = val;
        }

        vi arr;
        for(auto a : path){
            arr.push_back(size[a]);
        }
        ll j = path.size()-1;
        ll ops = j/2;
        
        ll total = 0;
        for(ll i=1; i<j; i++) total += arr[i];

        ll ptr1 = 1, ptr2 = j-1;

        ll res = 1;

        for(ll i=1; i<=ops; i++){
            res = (res*total)%mod;
            total -= arr[ptr1++];
            total -= arr[ptr2--];
        }

        cout << res << "\n";
    }
}