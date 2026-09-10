#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg, lazy;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void push(ll node, ll l, ll r){
        if(lazy[node]){
            seg[node] = (r-l+1) - seg[node];
            if(l!=r){
                lazy[2*node] ^= 1;
                lazy[2*node+1] ^= 1;
            }
            lazy[node] = 0;
        }
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    void update(ll node, ll l, ll r, ll ql, ll qr){
        push(node,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            lazy[node] ^= 1;
            push(node,l,r);
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node,l,m,ql,qr);
        update(2*node+1,m+1,r,ql,qr);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        push(node,l,r);
        if(ql>r || qr<l) return 0;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        for(ll i=1; i<n; i++){
            ll p; cin >> p; p--;
            adj[p].push_back(i);
        }
        vi arr(n); for(auto &x : arr) cin >> x;
        ll timer = 0;
        vi in(n), out(n), flatarr(n);
        auto dfs = [&](auto &&self, ll u)->void{
            in[u] = timer++;
            flatarr[in[u]] = arr[u];
            for(auto v : adj[u]){
                self(self,v);
            }
            out[u] = timer-1;
        };
        dfs(dfs,0);
        SegTree st(n);
        st.build(1,0,n-1,flatarr);
        ll q; cin >> q;
        while(q--){
            string s; cin >> s;
            ll v; cin >> v; v--;
            if(s=="pow"){
                st.update(1,0,n-1,in[v],out[v]);
            }else{
                cout << st.query(1,0,n-1,in[v],out[v]) << "\n";
            }
        }
    }
} 