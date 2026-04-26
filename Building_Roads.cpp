#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dfs(vector<vector<ll>> &adj, vector<bool> &vis, ll node){
    vis[node] = true;
    for(auto a : adj[node]){
        if(!vis[a]) dfs(adj, vis, a);
    }
}
int main() {
	ll n,m; cin >> n >> m;
	vector<vector<ll>> adj(n);
	while(m--){
	    ll u,v; cin >> u >> v;
	    u--; v--;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	vector<bool> vis(n, false);
	vector<ll> res;
	for(ll i=0; i<n; i++){
	    if(!vis[i]){
	        res.push_back(i);
	        dfs(adj, vis, i);
	    }
	}
	cout << res.size()-1 << "\n";
	for(ll i=1; i<res.size(); i++) cout << res[i-1]+1 << " " << res[i]+1 << "\n"; 
}
