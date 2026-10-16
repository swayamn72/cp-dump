#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Fenwick{
    ll n; vi bit;
    Fenwick(ll n){
        this->n = n;
        bit.resize(n+1,0);
    }
    void update(ll i, ll v){
        for(ll j=i; j<=n; j+=j&-j) bit[j]+=v;
    }
    ll get(ll i){
        ll res = 0;
        for(ll j=i; j>0; j-=j&-j) res += bit[j];
        return res;
    }
    ll getrange(ll l, ll r){
        return get(r) - get(l-1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll timer = 1;
        vi tin(n), tout(n), depth(n);
        auto dfs = [&](auto &&self, ll u, ll p, ll d)->void{
            tin[u] = timer++;
            depth[u] = d;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,d+1);
            }
            tout[u] = timer-1;
        };
        dfs(dfs,0,-1,0);
        Fenwick ft(n+1);
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll x,v; cin >> x >> v; x--;
                ll val = (depth[x]%2==1) ? -v : v;
                ft.update(tin[x], val);
                ft.update(tout[x]+1, -val);
            }else{
                ll x; cin >> x; x--;
                ll delta = ft.get(tin[x]);
                if(depth[x]%2) delta = -delta;
                cout << arr[x]+delta << "\n";
            }
        }
    }
}