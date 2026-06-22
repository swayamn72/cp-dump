#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi parent(n,-1), depth(n), tin(n), tout(n);
    ll timer = 0;
    auto dfs = [&](auto &&self, ll u, ll p, ll d)->void{
        tin[u] = timer++;
        parent[u] = p;
        depth[u] = d;
        for(auto v : adj[u]){
            if(v==p) continue;
            self(self,v,u,d+1);
        }
        tout[u] = timer++;
    };
    auto isancestor = [&](ll u, ll v)->bool{
        return tin[u]<=tin[v] && tout[u]>=tout[v];
    };
    dfs(dfs,0,-1,0);
    while(m--){
        ll k; cin >> k;
        vi arr(k); 
        for(auto &x : arr){
            cin >> x; x--;
        } 
        ll deep = arr[0];
        for(ll i=1; i<k; i++){
            if(depth[arr[i]]>depth[deep]){
                deep = arr[i];
            }
        }
        for(ll i=0; i<k; i++){
            if(parent[arr[i]]!=-1) arr[i] = parent[arr[i]];
        }
        bool flag = true;
        for(int i=0; i<k; i++){
            if(!isancestor(arr[i],deep)){
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}