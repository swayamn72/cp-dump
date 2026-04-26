#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll caseid = 1;
struct LCA{
    ll n, timer, root;
    vector<ll> euler, first, seg, depth;
    LCA(ll n, vector<vector<ll>>&adj, ll root){
        this->n = n;
        this->root = root;
        euler.reserve(2*n);
        depth.reserve(2*n);
        first.assign(n,-1);
        timer = 0;
        dfs(root,-1,0,adj);
        int m = euler.size();
        seg.assign(4*m+1,0);
        build(1,0,m-1);
    }
    void dfs(ll u, ll p, ll d, vector<vector<ll>>&adj){
        first[u] = timer++;
        euler.push_back(u);
        depth.push_back(d);
        for(auto v : adj[u]){
            if(v!=p){
                dfs(v,u,d+1,adj);
                timer++;
                euler.push_back(u);
                depth.push_back(d);
            }
        }
    }
    void build(ll node, ll l, ll r){
        if(l==r){
            seg[node] = l;
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m);
        build(2*node+1,m+1,r);
        ll leftindex = seg[2*node];
        ll rightindex = seg[2*node+1];
        if(depth[leftindex]<depth[rightindex]) seg[node] = leftindex;
        else seg[node] = rightindex;
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(qr<l || ql>r) return -1;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        ll leftindex = query(2*node,l,m,ql,qr);
        ll rightindex = query(2*node+1,m+1,r,ql,qr);
        if(leftindex==-1) return rightindex;
        if(rightindex==-1) return leftindex;
        if(depth[leftindex]<depth[rightindex]) return leftindex;
        else return rightindex;
    }
    ll get(ll u, ll v){
        ll left = first[u];
        ll right = first[v];
        if(left>right) swap(left,right);
        ll minindex = query(1,0,euler.size()-1,left,right);
        return euler[minindex];
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll t; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    vector<vector<ll>> adj(n);
	    vector<ll> indegree(n,0);
	    for(ll i=0; i<n; i++){
	        ll num; cin >> num;
	        for(ll j=0; j<num; j++){
	            ll val; cin >> val;
	            val--;
	            indegree[val]++;
	            adj[i].push_back(val);
	        }
	    }
	    ll root = -1;
	    for(ll i=0; i<n; i++){
	        if(indegree[i]==0){
	            root=i; break;
	        }
	    }
	    LCA lca(n,adj,root);
	    ll q; cin >> q;
	    cout << "Case " << caseid++ << ":" << "\n";
	    while(q--){
	        ll u,v; cin >> u >> v;
	        u--; v--;
	        ll res = lca.get(u,v) + 1;
	        cout << res << "\n";
	    }
	}
}
