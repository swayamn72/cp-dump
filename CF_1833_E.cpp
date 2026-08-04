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
        vi arr(n); 
        for(auto &x : arr){
            cin >> x; x--;
        }        
        vector<vector<ll>> edges;
        for(ll i=0; i<n; i++){
            ll u = i, v = arr[i];
            if(v<u) swap(u,v);
            edges.push_back({u,v});
        }
        sort(edges.begin(),edges.end());
        edges.erase(unique(edges.begin(),edges.end()), edges.end());
        vector<vector<ll>> adj(n);
        for(auto a : edges){
            ll u = a[0], v = a[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        
        vector<bool> vis(n,false);
        auto dfs = [&](auto &&self, ll u, ll p, ll &temp, vi &list)->void{
            list.push_back(u);
            vis[u] = true;
            for(auto v : adj[u]){
                if(v==p) continue;
                if(vis[v]){
                    temp++;
                    continue;
                }
                self(self,v,u,temp,list);
            }
        };
        ll count = 0;
        ll closed = 0;
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            count++;
            ll temp = 0;
            vi list;
            dfs(dfs,i,-1,temp,list);
            bool flag = true;
            for(auto a : list){
                if(adj[a].size()==1){
                    flag = false;
                    break;
                }
            }
            if(flag) closed++;
        }
        ll minv = closed;
        if(count>closed) minv++;
        cout << minv << " " << count << "\n";
    }
}