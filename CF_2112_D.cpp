#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }        
        if(n==2){
            cout << "NO" << "\n";
            continue;
        }
        // find leaf
        bool found = false;
        ll root = -1;
        for(ll i=0; i<n; i++){
            if(adj[i].size()==2){
                root = i;
                break;
            }
        }
        if(root==-1){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        ll u = adj[root][0], v = adj[root][1];
        cout << u+1 << " " << root+1 << "\n";
        cout << root+1 << " " << v+1 << "\n";
        auto dfs = [&](auto &&self, ll u, ll p, bool flag)->void{
            for(auto v : adj[u]){
                if(v==p) continue;
                if(flag){
                    cout << u+1 << " " << v+1 << "\n";
                }else{
                    cout << v+1 << " " << u+1 << "\n";
                }
                self(self,v,u,!flag);
            }
        };
        dfs(dfs,u,root,true);
        dfs(dfs,v,root,false);
    }
} 