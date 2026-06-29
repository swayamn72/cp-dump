#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vi arr(n); for(auto &x : arr) cin >> x;
    vector<vector<ll>> doors(n);
    for(ll i=0; i<m; i++){
        ll x; cin >> x;
        for(ll j=0; j<x; j++){
            ll u; cin >> u; u--;
            doors[u].push_back(i);
        }
    }
    vector<vector<ll>> adj(2*m), revadj(2*m);
    auto add = [&](ll u, ll v){
        adj[u].push_back(v);
        revadj[v].push_back(u);
    };
    for(ll i=0; i<n; i++){
        ll u = doors[i][0], v = doors[i][1];
        ll notu = 2*u+1, notv = 2*v+1;
        u*=2; v*=2;
        if(arr[i]==1){
            add(u,v); 
            add(v,u);
            add(notu,notv);
            add(notv,notu);
        }else{
            add(u,notv);
            add(notv,u);
            add(notu,v);
            add(v,notu);
        }
    }
    vi order;
    vector<bool> vis(2*m,false);
    auto dfs1 = [&](auto &&self, ll u)->void{
        vis[u] = true;
        for(auto v : adj[u]){
            if(vis[v]) continue;
            self(self,v);
        }
        order.push_back(u);
    };
    for(ll i=0; i<2*m; i++){
        if(!vis[i]) dfs1(dfs1,i);
    }
    reverse(order.begin(),order.end());
    vi comp(2*m);
    ll curr = 0;
    vis.assign(2*m,false);
    auto dfs2 = [&](auto &&self, ll u, ll curr)->void{
        vis[u] = true;
        comp[u] = curr;
        for(auto v : revadj[u]){
            if(vis[v]) continue;
            self(self,v,curr);
        }
    };
    for(auto a : order){
        if(!vis[a]){
            dfs2(dfs2,a,curr);
            curr++;
        }
    }
    bool flag = true;
    for(ll i=0; i<m; i++){
        if(comp[2*i]==comp[2*i+1]){
            flag = false;
            break;
        }
    }
    cout << (flag ? "YES" : "NO");
}