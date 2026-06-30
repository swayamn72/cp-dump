#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vector<pair<ll,ll>> edges(m);
    for(ll i=0; i<m; i++){
        ll a,b; cin >> a >> b;
        if(a>b) swap(a,b);
        edges[i] = {a,b};
    }
    vector<vector<ll>> adj(2*m), adjrev(2*m);
    auto add = [&](ll u, ll v){
        adj[u].push_back(v);
        adjrev[v].push_back(u);
    };
    for(ll i=0; i<m; i++){
        for(ll j=i+1; j<m; j++){
            auto [a,b] = edges[i];
            auto [u,v] = edges[j];
            bool intersecting = false;
            if(a<u && b>u && b<v) intersecting = true;
            if(a>u && a<v && b>v) intersecting = true;
            ll x = 2*i, y = 2*j;
            ll notx = x+1, noty = y+1;
            if(intersecting){
                add(x,noty);
                add(y,notx);
                add(notx,y);
                add(noty,x);
            }
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
    ll curr = 0;
    reverse(order.begin(),order.end());
    vi comp(2*m);
    vis.assign(2*m,false);
    auto dfs2 = [&](auto &&self, ll u, ll curr)->void{
        vis[u] = true;
        comp[u] = curr;
        for(auto v : adjrev[u]){
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
    if(!flag){
        cout << "Impossible";
        return 0;
    }
    string res = "";
    for(ll i=0; i<m; i++){
        ll u = 2*i, v = 2*i+1;
        if(comp[v]>comp[u]){
            res += 'o';
        }else{
            res += 'i';
        }
    }
    cout << res;
}