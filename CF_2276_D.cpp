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
        ll n,m; cin >> n >> m;
        vector<vi> adj(n);
        while(m--){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        bool flag = true;
        ll temp = 0;
        for(ll i=0; i<n; i++){
            if(adj[i].size()==0){
                flag = false;
                break;
            }
            if(adj[i].size()>1) temp++;
        }
        if(!flag){
            cout << "Brain Melt" << "\n";
            continue;
        }
        if(temp>1){
            cout << "Many" << "\n";
            continue;
        }
        vector<bool> vis(n,false);
        auto dfs = [&](auto &&self, ll u)->void{
            vis[u] = true;
            for(auto v : adj[u]){
                if(!vis[v]) self(self,v);
            }
        };
        ll cnt = 0;
        for(ll i=0; i<n; i++){
            if(!vis[i]){
                dfs(dfs,i); cnt++;
            }
        }
        if(cnt>1){
            cout << "Many" << "\n";
        }else{
            cout << 2 << "\n";
        }
    }
}