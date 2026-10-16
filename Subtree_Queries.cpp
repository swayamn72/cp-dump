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
    void add(ll i, ll v){
        for(ll j=i; j<=n; j+=j&-j) bit[j] += v;
    }
    ll get(ll i){
        ll res = 0;
        for(ll j=i; j>0; j-=(j&-j)) res += bit[j];
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
            ll a,b; cin >> a >> b; a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        Fenwick ft(n+1);
        vi tin(n), tout(n);
        ll timer = 1;
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            tin[u] = timer++;
            ft.add(tin[u],arr[u]);
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
            tout[u] = timer-1;
        };
        dfs(dfs,0,-1);
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll s,x; cin >> s >> x; s--;
                ll curr = arr[s];
                ll delta = x-curr;
                arr[s] = x;
                ft.add(tin[s],delta);
            }else{
                ll s; cin >> s; s--;
                cout << ft.getrange(tin[s], tout[s]) << "\n";
            }
        }
    }
}