#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Node{
    ll sum, prefmax, prefmin, suffmax, suffmin, maxv, minv;
};
Node create(ll val){
    return {val,max(0LL,val),min(0LL,val),max(0LL,val),min(0LL,val),max(0LL,val),min(0LL,val)};
}
Node empty(){ return {0,0,0,0,0,0,0};}
Node merge(Node a, Node b){
    Node res;
    res.sum = a.sum + b.sum;
    res.prefmax = max(a.prefmax,a.sum+b.prefmax);
    res.prefmin = min(a.prefmin,a.sum+b.prefmin);
    res.suffmax = max(b.suffmax,b.sum+a.suffmax);
    res.suffmin = min(b.suffmin,b.sum+a.suffmin);
    res.maxv = max({a.maxv,b.maxv,a.suffmax+b.prefmax});
    res.minv = min({a.minv,b.minv,a.suffmin+b.prefmin});
    return res;
}
Node rev(Node a){
    swap(a.prefmax,a.suffmax);
    swap(a.prefmin,a.suffmin);
    return a;
}
struct BinaryLift{
    ll n,root,l,timer;
    vi tin,tout,depth;
    vector<vi> up;
    vector<vector<Node>> upinfo;
    BinaryLift(ll n, ll root, vector<vi> &adj, vi &arr){
        this->n = n;
        this->root = root;
        timer = 0;
        l = ceil(log2(n))+1;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.resize(n,vi(l+1));
        upinfo.assign(n,vector<Node>(l+1,empty()));
        dfs(root,root,0,adj,arr);
    }
    void dfs(ll u, ll p, ll d, vector<vi> &adj, vi &arr){
        tin[u] = timer++;
        depth[u] = d;
        up[u][0] = p;
        upinfo[u][0] = create(arr[u]);
        for(ll i=1; i<=l; i++){
            up[u][i] = up[up[u][i-1]][i-1];
            
            if(depth[u]>=(1LL<<i)){
                upinfo[u][i] = merge(upinfo[u][i-1],upinfo[up[u][i-1]][i-1]);
            }else{
                upinfo[u][i] = upinfo[u][i-1];
            }
        }
        for(auto v : adj[u]){
            dfs(v,u,d+1,adj,arr);
        }
        tout[u] = timer++;
    }
    bool isancestor(ll u, ll v){
        return tin[u]<=tin[v] && tout[u]>=tout[v];
    }
    ll getlca(ll u, ll v){
        if(isancestor(u, v)) return u;
        if(isancestor(v, u)) return v;
        for(ll i=l; i>=0; i--){
            if(!isancestor(up[u][i],v)) u = up[u][i];
        }
        return up[u][0];
    }
    Node getpath(ll u, ll targetdepth){
        Node res = empty();
        for(ll i=l; i>=0; i--){
            if(depth[u]-(1LL<<i)>=targetdepth){
                res = merge(res,upinfo[u][i]);
                u = up[u][i];
            }
        }
        return res;
    }
};  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n+1);
        vi arr(n+1);
        arr[0] = 1;
        ll curr = 0;
        vector<vi> queries;
        for(ll i=0; i<n; i++){
            char ch; cin >> ch;
            if(ch=='+'){
                ll v,x; cin >> v >> x; v--;
                curr++;
                arr[curr] = x;
                adj[v].push_back(curr);  
            }else{
                ll u,v,k; cin >> u >> v >> k;
                queries.push_back({u-1,v-1,k});
            }
        }
        BinaryLift bl(curr+1,0,adj,arr);
        for(auto &a : queries){
            ll u = a[0], v = a[1], k = a[2];
            if(k==0){
                cout << "YES" << "\n";
                continue;
            }
            ll lca = bl.getlca(u, v);

            Node L = bl.getpath(u, bl.depth[lca]);
            Node R = bl.getpath(v, bl.depth[lca]);
            Node m = create(arr[lca]);
            Node ans = merge(L,merge(m, rev(R)));
            
            if(k>=ans.minv && k<=ans.maxv) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}