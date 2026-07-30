#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<vector<ll>> revadj(n);
    while(m--){
        ll u,v; cin >> u >> v;
        adj[u].push_back(v);
        revadj[v].push_back(u);
    }
    vector<bool> vis(n,false);
    vi order;
    auto dfs1 = [&](auto &&self, ll u)->void{
        vis[u] = true;
        for(auto v : adj[u]){
            if(!vis[v]) self(self,v);
        }
        order.push_back(u);
    };
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs1(dfs1,i);
    }
    vis.assign(n,false);
    reverse(order.begin(),order.end());
    vector<vector<ll>> res;
    auto dfs2 = [&](auto &&self, ll u, vi &temp)->void{
        temp.push_back(u);
        vis[u] = true;
        for(auto v : revadj[u]){
            if(!vis[v]) self(self,v,temp);
        }
    };
    for(auto a : order){
        if(!vis[a]){
            vi temp;
            dfs2(dfs2,a,temp);
            res.push_back(temp);
        } 
    }
    cout << res.size() << "\n";
    for(auto &a : res){
        cout << a.size() << " ";
        for(auto b : a) cout << b << " ";
        cout << "\n";
    } 
}