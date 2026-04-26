#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

bool bfs(vector<vector<ll>> &adj, ll node, vi &vis, ll s, ll id){
    if(vis[node]!=-1 && vis[node]!=id) return false;
    queue<ll> q; q.push(node);
    vis[node] = id;
    ll size = 1;
    
    while(!q.empty()){
        ll curr = q.front(); q.pop(); size--;
        if(s > 0) {
            for(auto a : adj[curr]){
                if(vis[a]==id) continue;
                if(vis[a]!=-1 && vis[a]!=id){
                    return false;
                }
                vis[a] = id;
                q.push(a);
            }
        }
        
        if(size==0){
            size = q.size(); s--;
        }
        if(s==-1) break;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,r,m; cin >> n >> r >> m;
        bool flag = true;
        vector<vector<ll>> adj(n);
        while(r--){
            ll a,b; cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        vi vis(n,-1);
        ll id = 0;
        while(m--){
            ll k,s; cin >> k >> s;
            k--;
            if(flag) {
                bool temp = bfs(adj,k,vis,s,id);
                if(!temp){
                    flag = false;
                }
            }
            id++;
        }
        
        for(auto a : vis) {
            if(a == -1) flag = false;
        }
        
        if(!flag) cout << "No" << "\n";
        else cout << "Yes" << "\n";
    }
}