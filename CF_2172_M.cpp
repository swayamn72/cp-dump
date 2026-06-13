#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t = 1;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vi arr(n); for(auto &x : arr){
            cin >> x; x--;
        } 
        // 1 0 0
        vector<vector<ll>> adj(n);
        // 0 : 1 2
        // 1 : 0 2
        // 2 : 0 1
        while(m--){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v); adj[v].push_back(u);
        }        
        vi res(k,-1);
        queue<ll> q; q.push(0);
        ll size = 1;
        ll dist = 0;
        vector<bool> vis(n,false); vis[0] = true;
        while(!q.empty()){
            ll u = q.front(); q.pop();
            res[arr[u]] = dist;
            size--;
            for(auto v : adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                } 
            }
            if(size==0){
                dist++;
                size = q.size();
            }
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}