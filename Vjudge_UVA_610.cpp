#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    ll t = 1;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        cout << t << "\n\n" ;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<m; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll timer = 0;
        vector<ll> tin(n,-1), low(n,-1);
        vector<bool> vis(n,false);
        function<void(ll,ll)> dfs = [&](ll u, ll p){
            tin[u] = low[u] = timer++;
            vis[u] = true;
            for(auto v : adj[u]){
                if(v==p) continue;
                if(vis[v]){
                    low[u] = min(low[u], tin[v]);
                    if(tin[v]<tin[u]) cout << u+1 << " " << v+1 << "\n";
                }else{
                    cout << u+1 << " " << v+1 << "\n";
                    dfs(v,u);
                    low[u] = min(low[u],low[v]);
                    if(low[v]>tin[u]) cout << v+1 << " " << u+1 << "\n";
                }
            }
        };
        // auto dfs = [&](auto &&self, ll u, ll p) -> void{
        //     tin[u] = low[u] = timer++;
        //     vis[u] = true;
        //     for(auto v : adj[u]){
        //         if(v==p) continue;
        //         if(vis[v]){
        //             low[u] = min(low[u], tin[v]);
        //             if(tin[v]<tin[u]) cout << u+1 << " " << v+1 << "\n";
        //         }else{
        //             cout << u+1 << " " << v+1 << "\n";
        //             self(self,v,u);
        //             low[u] = min(low[u],low[v]);
        //             if(low[v]>tin[u]) cout << v+1 << " " << u+1 << "\n";
        //         }
        //     }
        // };
        // dfs(dfs,0,-1);
        dfs(0,-1);
        cout << "#" << "\n";
        t++;
    }
}