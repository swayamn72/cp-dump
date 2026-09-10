#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct SegTree{
    ll n,m;
    vector<vector<pair<ll,ll>>> adj;
    vi in, out;
    SegTree(ll n){
        this->n = n;
        m = n;
        adj.resize(9*n+5);
        in.resize(4*n+5);
        out.resize(4*n+5);
    }
    void buildin(ll node, ll l, ll r){
        if(l==r){
            in[node] = l;
            return;
        }
        in[node] = ++m;
        ll m = l + (r-l)/2;
        buildin(2*node,l,m);
        buildin(2*node+1,m+1,r);
        adj[in[node]].push_back({in[2*node],0});
        adj[in[node]].push_back({in[2*node+1],0});
    }
    void buildout(ll node, ll l, ll r){
        if(l==r){
            out[node] = l;
            return;
        }
        out[node] = ++m;
        ll m = l + (r-l)/2;
        buildout(2*node,l,m);
        buildout(2*node+1,m+1,r);
        adj[out[2*node]].push_back({out[node],0});
        adj[out[2*node+1]].push_back({out[node],0});
    }
    void updatein(ll node, ll l, ll r, ll ql, ll qr, ll u, ll w){
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            adj[u].push_back({in[node],w});
            return;
        }
        ll m = l + (r-l)/2;
        updatein(2*node,l,m,ql,qr,u,w);
        updatein(2*node+1,m+1,r,ql,qr,u,w);
    }
    void updateout(ll node, ll l, ll r, ll ql, ll qr, ll v, ll w){
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            adj[out[node]].push_back({v,w});
            return;
        }
        ll m = l + (r-l)/2;
        updateout(2*node,l,m,ql,qr,v,w);
        updateout(2*node+1,m+1,r,ql,qr,v,w);
    }
    void addedge(ll u, ll v, ll w){
        adj[u].push_back({v,w});
    }
    vi dijkstra(ll s){
        vi dist(m+1,LLONG_MAX);
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        dist[s] = 0;
        pq.push({0,s});
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d>dist[u]) continue;
            for(auto [v,w] : adj[u]){
                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,q,s; cin >> n >> q >> s;
        SegTree st(n);
        st.buildin(1,1,n);
        st.buildout(1,1,n);
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll u,v,w; cin >> u >> v >> w;
                st.addedge(u,v,w);
            }else if(type==2){
                ll u,l,r,w; cin >> u >> l >> r >> w;
                st.updatein(1,1,n,l,r,u,w);
            }else{
                ll v,l,r,w; cin >> v >> l >> r >> w;
                st.updateout(1,1,n,l,r,v,w);
            }
        }
        vi dist = st.dijkstra(s);
        for(ll i=1; i<=n; i++){
            cout << (dist[i]==LLONG_MAX ? -1 : dist[i]) << " ";
        }
    }
} 