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
        seg.resize(4*n+1);
        lazy.resize(4*n+1,-1);
    }
    void push(ll node, ll l, ll r){
        if(lazy[node]!=-1){
            seg[node] = (r-l+1)*lazy[node];
            if(l!=r){
                lazy[2*node] = lazy[node];
                lazy[2*node+1] = lazy[node];
            }
            lazy[node] = -1;
        }
    }
    void build(ll node, ll l, ll r){
        if(l==r){
            seg[node] = 1;
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m);
        build(2*node+1,m+1,r);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll v){
        push(node,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            lazy[node] = v;
            push(node,l,r);
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node,l,m,ql,qr,v);
        update(2*node+1,m+1,r,ql,qr,v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        push(node,l,r);
        if(ql>r || qr<l) return 0LL;
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
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll timer = 0;
        vi in(n), out(n), parent(n);
        auto dfs = [&](auto &&self, ll u, ll p)->void{
            in[u] = timer++;
            parent[u] = p;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
            }
            out[u] = timer-1;
        };
        dfs(dfs,0,-1);
        SegTree st(n);
        st.build(1,0,n-1);
        ll q; cin >> q;
        while(q--){
            ll type; cin >> type;
            ll v; cin >> v;
            v--;
            if(type==1){
                ll curr = st.query(1,0,n-1,in[v],out[v]);
                if(curr>0 && parent[v]!=-1){
                    st.update(1,0,n-1,in[parent[v]],in[parent[v]],1);
                }
                st.update(1,0,n-1,in[v],out[v],0);
            }else if(type==2){
                st.update(1,0,n-1,in[v],in[v],1);
            }else{
                ll curr = st.query(1,0,n-1,in[v],out[v]);
                if(curr>0) cout << 0 << "\n";
                else cout << 1 << "\n";
            }
        }
    }
} 