#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct CD{
    ll n;
    vi subtree, parent;
    vector<bool> removed;
    CD(ll n){
        this->n = n;
        subtree.resize(n,0);
        removed.resize(n,false);
        parent.resize(n,-1);
    }
    ll getsubtreesize(ll u, ll p, vector<vector<ll>>&adj){
        subtree[u] = 1;
        for(auto v : adj[u]){
            if(v==p || removed[v]) continue;
            subtree[u] += getsubtreesize(v,u,adj);
        }
        return subtree[u];
    }
    ll getcentroid(ll u, ll p, ll treesize, vector<vector<ll>>&adj){
        for(auto v : adj[u]){
            if(v==p || removed[v]) continue;
            if(subtree[v]>(treesize/2)){
                return getcentroid(v,u,treesize,adj);
            } 
        }
        return u;
    }
    void decompose(ll u, ll pcentroid, vector<vector<ll>>&adj){
        ll treesize = getsubtreesize(u,-1,adj);
        ll centroid = getcentroid(u,-1,treesize,adj);
        parent[centroid] = pcentroid;
        removed[centroid] = true;
        for(auto v : adj[centroid]){
            if(!removed[v]){
                decompose(v,centroid,adj);
            }
        }
    }
    void solve(vector<vector<ll>>&adj){
        decompose(0,-1,adj);
        for(auto a : parent){
            cout << (a==-1 ? -1 : a+1) << " ";
        } 
        cout << "\n";
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t = 1;
    while(t--){
        ll n; cin >> n;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        CD cd(n);
        cd.solve(adj);
    }
}