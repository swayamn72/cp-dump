#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
void bfs(vector<vector<ll>>&adj, vector<bool>&vis, ll i){
    queue<ll> q; q.push(i);
    while(!q.empty()){
        ll node = q.front(); q.pop();
        for(auto a : adj[node]){
            if(!vis[a]){
                vis[a] = true;
                q.push(a);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n; i++){
            ll val = arr[i]-1;
            adj[i].push_back(val);
            adj[val].push_back(i);
        }
        vector<bool> vis(n,false);
        ll size = 0;
        for(ll i=0; i<n; i++){
            if(!vis[i]){
                bfs(adj,vis,i);
                size++;
            }
        }
        cout << n-size << "\n";
    }
}