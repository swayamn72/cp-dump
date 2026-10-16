#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Fenwick{
    ll n; vi tree;
    Fenwick(ll n){
        this->n = n;
        tree.assign(n,0);
    }
    void add(ll i, ll delta){
        for(; i<n; i+=i&-i) tree[i] += delta;
    }
    ll query(ll i){
        ll sum = 0;
        for(; i>0; i-=i&-i) sum+=tree[i];
        return sum;
    }
    ll query(ll l, ll r){
        return query(r) - query(l-1);
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
        vector<pair<ll,ll>> edges(n-1);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i] = {u,v};
        }
        ll root = 0;
        for(ll i=1; i<n; i++){
            if(adj[i].size()>2){
                root=i; break;
            }
        }
        vi branchid(n), depth(n), pos(n);
        ll timer = 1;
        auto dfs = [&](auto &&self, ll u, ll p, ll id, ll d)->void{
            branchid[u] = id;
            depth[u] = d;
            pos[u] = timer++;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,(u==root ? v : id),d+1);
            }
        };
        depth[root] = 0;
        pos[root] = timer++;
        for(auto v : adj[root]) dfs(dfs,v,root,v,1);

        vi edgetonode(n-1);
        for(ll i=0; i<n-1; i++){
            auto [u,v] = edges[i];
            edgetonode[i] = (depth[u]>depth[v] ? u : v);
        }

        Fenwick ft(n+2);
        vi isbroken(n-1,0);
        auto getdist = [&](ll u, ll v)->ll{
            if(u==v) return 0LL;
            // case 1 : touches root
            if(u==root || v==root){
                ll target = (u==root ? v : u);
                if(ft.query(pos[branchid[target]],pos[target])>0) return -1;
                return depth[target];
            }
            // case 2 : same branch
            if(branchid[u]==branchid[v]){
                if(depth[u]>depth[v]) swap(u,v);
                if(ft.query(pos[u]+1,pos[v])>0) return -1;
                return depth[v]-depth[u];
            }
            // case 3 : diff branches
            ll sumu = ft.query(pos[branchid[u]],pos[u]);
            ll sumv = ft.query(pos[branchid[v]],pos[v]);
            if(sumu+sumv>0) return -1;
            return depth[u]+depth[v];
        };
        ll m; cin >> m;
        while(m--){
            ll type; cin >> type;
            if(type==1){
                ll i; cin >> i; i--;
                if(isbroken[i]){
                    ft.add(pos[edgetonode[i]],-1);
                    isbroken[i] = 0;
                }
            }else if(type==2){
                ll i; cin >> i; i--;
                if(!isbroken[i]){
                    ft.add(pos[edgetonode[i]],1);
                    isbroken[i] = 1;
                }
            }else{
                ll u,v; cin >> u >> v; u--; v--;
                cout << getdist(u, v) << "\n";
            }
        }
    }
}