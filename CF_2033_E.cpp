#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
void dfs(vector<vector<ll>>&adj, ll u, vector<bool>&vis, ll &count){
    vis[u] = true;
    count++;
    for(auto v : adj[u]){
        if(!vis[v]) dfs(adj,v,vis,count);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        vector<vector<ll>> adj(n+1);
        for(int i=0; i<n; i++){
            adj[i+1].push_back(arr[i]);
            adj[arr[i]].push_back(i+1);
        }
        vector<bool> vis(n+1,false);
        ll res = 0;
        for(ll i=1; i<=n; i++){
            if(!vis[i]){
                ll count = 0;
                dfs(adj, i, vis, count);
                res += (count-1)/2;
            }
        }        
        cout << res << "\n";
    }
}