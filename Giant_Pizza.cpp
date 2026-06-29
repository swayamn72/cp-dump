#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vector<vector<ll>> adj(2*m), revadj(2*m);
    for(ll i=0; i<n; i++){
        char op1,op2; ll u,v; cin >> op1 >> u >> op2 >> v;
        u--; v--; u*=2; v*=2;
        ll notu = u+1, notv = v+1;
        if(op1=='+' && op2=='+'){
            adj[notu].push_back(v);
            adj[notv].push_back(u);
            revadj[v].push_back(notu);
            revadj[u].push_back(notv);
        }else if(op1=='-' && op2=='-'){
            adj[u].push_back(notv);
            adj[v].push_back(notu);
            revadj[notv].push_back(u);
            revadj[notu].push_back(v);
        }else if(op1=='+' && op2=='-'){
            adj[notu].push_back(notv);
            adj[v].push_back(u);
            revadj[notv].push_back(notu);
            revadj[u].push_back(v);
        }else{
            adj[u].push_back(v);
            adj[notv].push_back(notu);
            revadj[v].push_back(u);
            revadj[notu].push_back(notv);
        }
    }
    vector<bool> vis(2*m,false);
    vi order;
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
    ll scc = 0;
    vis.assign(2*m,false);
    auto dfs2 = [&](auto &&self, ll u, ll p)->void{
        comp[u] = scc;
        vis[u] = true;
        for(auto v : revadj[u]){
            if(vis[v]) continue;
            self(self,v,p);
        }
    };
    for(auto a : order){
        if(!vis[a]){
            dfs2(dfs2,a,a);
            scc++;
        }
    }
    vector<char> res(m);
    for(ll i=0; i<m; i++){
        ll u = 2*i, v = 2*i+1;
        if(comp[u]==comp[v]){
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
        if(comp[u]>comp[v]){
            res[i] = '+';
        }else{
            res[i] = '-';
        }
    }
    for(auto a : res) cout << a << " ";
}