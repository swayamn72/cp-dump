#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg;
    SegTree(){}
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return max(query(2*node,l,m,ql,qr),query(2*node+1,m+1,r,ql,qr));
    }
};
struct HLD{
    ll n, timer;
    vi depth,size,heavy,head,pos,parent;
    SegTree st;
    HLD(ll n, vector<vi>&adj, vi &arr){
        this->n = n;
        timer = 0;
        depth.resize(n,0);
        size.resize(n,0);
        parent.resize(n,-1);
        heavy.resize(n,-1);
        head.resize(n,0);
        pos.resize(n,0);
        dfs1(0,-1,0,adj);
        dfs2(0,-1,0,adj);
        vi flatarr(n);
        for(ll i=0; i<n; i++){
            flatarr[pos[i]] = arr[i];
        }
        st = SegTree(n);
        st.build(1,0,n-1,flatarr);
    }
    void dfs1(ll u, ll p, ll d, vector<vi>&adj){
        parent[u] = p;
        depth[u] = d;
        size[u] = 1;
        ll maxsub = 0;
        for(auto v : adj[u]){
            if(v==p) continue;
            dfs1(v,u,d+1,adj);
            size[u] += size[v];
            if(size[v]>maxsub){
                maxsub = size[v];
                heavy[u] = v;
            }
        } 
    }
    void dfs2(ll u, ll p, ll h, vector<vi>&adj){
        head[u] = h;
        pos[u] = timer++;
        if(heavy[u]!=-1) dfs2(heavy[u],u,h,adj);
        for(auto v : adj[u]){
            if(v==p || v==heavy[u]) continue;
            dfs2(v,u,v,adj);
        }
    }
    void updatenode(ll u, ll val){
        st.update(1,0,n-1,pos[u],val);
    }
    ll querypath(ll u, ll v){
        ll res = 0;
        while(head[u]!=head[v]){
            if(depth[head[u]]<depth[head[v]]) swap(u,v);
            res = max(res,st.query(1,0,n-1,pos[head[u]], pos[u]));
            u = parent[head[u]];
        }
        if(depth[u] > depth[v]) swap(u, v);
        res = max(res,st.query(1,0,n-1,pos[u],pos[v])); 
        return res;
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
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        HLD hld(n,adj,arr);
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll s,x; cin >> s >> x;
                s--;
                hld.updatenode(s,x);
            }else{
                ll a,b; cin >> a >> b;
                a--; b--;
                cout << hld.querypath(a,b) << " ";
            }
        }
    }
} 