#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
// struct LCA{
//     ll n;
//     vector<ll> euler, first, seg, height; 
//     vector<bool> vis;
//     LCA(ll n, vector<vector<ll>> &adj, ll root){
//         this->n = n;
//         euler.reserve(2*n);
//         first.resize(n);
//         height.resize(n);
//         vis.assign(n,false);
//         dfs(root, 0, adj);
//         ll m = euler.size();
//         seg.resize(4*m);
//         build(1,0,m-1);
//     }
//     void dfs(ll node, ll h, vector<vector<ll>> &adj){
//         vis[node] = true;
//         first[node] = euler.size();
//         height[node] = h;
//         euler.push_back(node);
//         for(auto a : adj[node]){
//             if(vis[a]) continue;
//             dfs(a,h+1,adj);
//             euler.push_back(node);
//         }  
//     }
//     void build(ll node, ll l, ll r){
//         if(l==r){
//             seg[node] = euler[l];
//             return;
//         }
//         ll m = l + (r-l)/2;
//         build(2*node,l,m);
//         build(2*node+1,m+1,r);
//         if(height[seg[2*node]] < height[seg[2*node+1]]){
//             seg[node] = seg[2*node];
//         }else{
//             seg[node] = seg[2*node+1];
//         }
//     }
//     ll query(ll node, ll l, ll r, ll ql, ll qr){
//         if(qr<l || ql>r) return -1;
//         if(ql<=l && qr>=r) return seg[node];
//         ll m = l + (r-l)/2;
//         ll left = query(2*node,l,m,ql,qr);
//         ll right = query(2*node+1,m+1,r,ql,qr);
//         if(left==-1) return right;
//         if(right==-1) return left;
//         if(height[left]<height[right]) return left;
//         else return right;
//     }
//     ll lcancestor(ll u, ll v){
//         ll l = first[u], r = first[v];
//         if(l>r) swap(l,r);
//         return query(1,0,euler.size()-1,l,r);
//     }
// };
struct LCA{
    ll n, timer, l; 
    vi tin, tout;
    vector<vector<ll>> up;
    LCA(ll n, vector<vector<ll>> &adj, ll root){
        this->n = n;
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        l = ceil(log2(n));
        up.assign(n, vector<ll>(l+1));
        dfs(root,root,adj);
    }
    void dfs(ll node, ll p, vector<vector<ll>> &adj){
        up[node][0] = p;
        tin[node] = timer++;
        for(ll i=1; i<=l; i++){
            up[node][i] = up[up[node][i-1]][i-1];
        }
        for(auto a : adj[node]){
            if(a==p) continue;
            dfs(a,node,adj);
        }
        tout[node] = timer++;
    }
    bool isancestor(ll u, ll v){
        return tin[u]<=tin[v] && tout[u]>=tout[v];
    }
    int lcancestor(ll u, ll v){
        if(isancestor(u,v)) return u;
        else if(isancestor(v,u)) return v;
        for(ll i=l; i>=0; i--){
            if(!isancestor(up[u][i],v)){
                u = up[u][i];
            }
        }
        return up[u][0];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll testcase = 1;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<ll>> adj(n);
        vi indegree(n);
        for(ll i=0; i<n; i++){
            ll m; cin >> m;
            for(ll j=0; j<m; j++){
                ll x; cin >> x; x--;
                adj[i].push_back(x);
                indegree[x]++;
            }
        }
        ll root;
        for(ll i=0; i<n; i++){
            if(indegree[i]==0){
                root = i;
                break;
            }
        } 

        LCA lca(n,adj,root);
        // lca.printfirst();
        ll q; cin >> q;
        cout << "Case " << testcase++ << ":" << "\n";
        while(q--){
            ll u,v; cin >> u >> v; u--; v--;
            cout << lca.lcancestor(u,v)+1 << "\n";
        }
    }
}