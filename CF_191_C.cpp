#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg, lazyadd;
    SegTree(){}
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1);
        lazyadd.resize(4*n+1);
    }
    void applyadd(ll node, ll l, ll r, ll val){
        lazyadd[node] += val;
        seg[node] += val * (r-l+1);
    }
    void push(ll node, ll l, ll r){
        if(l==r) return;
        ll m = l + (r-l)/2;
        if(lazyadd[node]!=0){
            ll val = lazyadd[node];
            applyadd(2*node,l,m,val);
            applyadd(2*node+1,m+1,r,val);
            lazyadd[node] = 0;
        }
    }
    void updateadd(ll node, ll l, ll r, ll ql, ll qr, ll v){
        if(qr<l || ql>r) return;
        if(ql<=l && qr>=r){
            applyadd(node,l,r,v);
            return;
        }
        push(node,l,r);
        ll m = l + (r-l)/2;
        updateadd(2*node,l,m,ql,qr,v);
        updateadd(2*node+1,m+1,r,ql,qr,v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(qr<l || ql>r) return 0;
        if(ql<=l && qr>=r) return seg[node];
        push(node,l,r);
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
    }
};
struct HLD{
    ll n,timer;
    vi depth, size, parent, heavy, head, pos;
    SegTree st;
    HLD(ll n, vector<vector<ll>> adj){
        timer = 0;
        this->n = n;
        depth.resize(n,0);
        size.resize(n,0);
        parent.resize(n,-1);
        heavy.resize(n,-1);
        head.resize(n,0);
        pos.resize(n,0);
        st = SegTree(n);
        dfs1(0,-1,0,adj);
        dfs2(0,-1,0,adj);
    }
    void dfs1(ll u, ll p, ll d, vector<vector<ll>> &adj){
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
    void dfs2(ll u, ll p, ll h, vector<vector<ll>>&adj){
        head[u] = h;
        pos[u] = timer++;
        if(heavy[u]!=-1){
            dfs2(heavy[u],u,h,adj);
        }
        for(auto v : adj[u]){
            if(v==p || v==heavy[u]) continue;
            dfs2(v,u,v,adj);
        }
    }
    void updatepath(ll u, ll v, ll val){
        while(head[u]!=head[v]){
            if(depth[head[u]]<depth[head[v]]){
                swap(u,v);
            }
            st.updateadd(1,0,n-1,pos[head[u]],pos[u],val);
            u = parent[head[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        if(pos[u]<pos[v]){
            st.updateadd(1,0,n-1,pos[u]+1,pos[v],val);
        }
    }
    ll query(ll u){
        return st.query(1,0,n-1,pos[u],pos[u]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<vector<ll>> adj(n); vector<pair<ll,ll>> edges(n-1);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u,v};
    }
    HLD hld(n,adj);
    ll k; cin >> k;
    for(ll i=0; i<k; i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        hld.updatepath(a,b,1);
    }
    for(auto [u,v] : edges){
        ll node = u;
        if(hld.depth[v]>hld.depth[u]) node = v;
        cout << hld.query(node) << " ";
    }
}
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using vi = vector<ll>;
// struct LCA{
//     ll n,timer,l;
//     vi tin, tout, depth;
//     vector<vector<ll>> up;
//     LCA(ll n, vector<vector<ll>>&adj){
//         this->n = n;
//         timer = 0;
//         tin.resize(n);
//         tout.resize(n);
//         depth.resize(n);
//         l = ceil(log2(n));
//         up.assign(n, vector<ll>(l+1));
//         dfs(0,0,0,adj);
//     }
//     void dfs(ll u, ll p, ll d, vector<vector<ll>>&adj){
//         tin[u] = timer++;
//         depth[u] = d;
//         up[u][0] = p;
//         for(ll i=1; i<=l; i++) up[u][i] = up[up[u][i-1]][i-1];
//         for(auto v : adj[u]){
//             if(v==p) continue;
//             dfs(v,u,d+1,adj);
//         }
//         tout[u] = timer++;
//     }
//     bool isancestor(ll u, ll v){
//         return tin[u]<=tin[v] && tout[u]>=tout[v];
//     }
//     ll lca(ll u, ll v){
//         if(isancestor(u,v)) return u;
//         if(isancestor(v,u)) return v;
//         for(ll i=l; i>=0; i--){
//             if(!isancestor(up[u][i], v)){
//                 u = up[u][i];
//             }
//         }
//         return up[u][0];
//     }
// };
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//     ll n; cin >> n;
//     vector<vector<ll>> adj(n);
//     vector<pair<ll,ll>> edges(n-1);
//     for(ll i=0; i<n-1; i++){
//         ll u,v; cin >> u >> v;
//         u--; v--;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         edges[i] = {u,v};
//     }
//     LCA lca(n,adj);
//     ll k; cin >> k;

//     vector<ll> res(n,0);

//     for(ll i=0; i<k; i++){
//         ll a,b; cin >> a >> b;
//         a--; b--;
//         ll lcanode = lca.lca(a,b);
//         res[a]++; res[b]++; res[lcanode]-=2;
//     }
//     vi subtreesize(n);
//     auto dfs = [&](auto &&self, ll u, ll p)->ll{
//         ll size = res[u];
//         for(auto v : adj[u]){
//             if(v==p) continue;
//             ll temp = self(self,v,u);
//             size += temp;
//         }
//         subtreesize[u] = size;
//         return size;
//     };
//     dfs(dfs,0,-1);
//     for(ll i=0; i<n-1; i++){
//         auto [u,v] = edges[i];
//         ll node = u;
//         if(lca.depth[v]>lca.depth[u]) node = v;
//         cout << subtreesize[node] << " ";
//     }
// }