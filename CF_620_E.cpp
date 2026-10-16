#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg; vi lazy;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    // vi merge(vi &a, vi &b){
    //     vi v = a;
    //     for(ll i=0; i<=60; i++) v[i] += b[i];
    //     return v;
    // }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = 1LL << arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = seg[2*node] | seg[2*node+1];
    }
    void push(ll node, ll l, ll r){
        if(lazy[node]!=0){
            seg[node] = 1LL << lazy[node];
            if(l!=r){
                lazy[2*node] = lazy[node];
                lazy[2*node+1] = lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll v){
        push(node,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            seg[node] = 1LL << v;
            if(l!=r){
                lazy[2*node] = v;
                lazy[2*node+1] = v;
            }
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node,l,m,ql,qr,v);
        update(2*node+1,m+1,r,ql,qr,v);
        seg[node] = seg[2*node] | seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        push(node, l, r);
        if(qr<l || ql>r) return 0;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node, l, m, ql, qr) | query(2*node+1, m+1, r, ql, qr);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vi> adj(n); 
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi tin(n), tout(n);
        ll timer = 0;
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            tin[u] = timer++;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
            tout[u] = timer-1;
        };
        dfs(dfs,0,-1);
        SegTree st(n+1);
        vi flat(n+1);
        for(ll i=0; i<n; i++){
            flat[tin[i]] = arr[i];
        }
        st.build(1, 0, n-1, flat);
        while(m--){
            ll type; cin >> type;
            if(type==1){
                ll v,c; cin >> v >> c; v--;
                st.update(1, 0, n-1, tin[v], tout[v], c);
            }else{
                ll v; cin >> v; v--;
                ll ans = st.query(1, 0, n-1, tin[v], tout[v]);
                cout << __builtin_popcountll(ans) << "\n";
            }
        }
    }
}