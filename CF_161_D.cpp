#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct CD{
    ll n,k,maxdepth,paths;
    vector<bool> removed;
    vi subtree,count;
    CD(ll n, ll k){
        this->n = n;
        this->k = k;
        removed.resize(n,false);
        paths = 0;
        maxdepth = 0;
        count.resize(max(k+1,n+1),0);
        subtree.resize(n,0);
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
    void getdist(ll u, ll p, ll dist, bool counting, vector<vector<ll>>&adj){
        if(dist>k) return;
        if(counting){
            paths += count[k-dist];
        }else{
            count[dist]++;
            maxdepth = max(maxdepth,dist);
        }
        for(auto v : adj[u]){
            if(v==p || removed[v]) continue;
            getdist(v,u,dist+1,counting,adj);
        }
    }
    void processcentroid(ll centroid, vector<vector<ll>>&adj){
        maxdepth = 0;
        count[0] = 1;
        for(auto v : adj[centroid]){
            if(removed[v]) continue;
            getdist(v,centroid,1,true,adj);
            getdist(v,centroid,1,false,adj);
        }
        fill(count.begin(),count.begin()+maxdepth+1,0);
    }
    void decompose(ll u, vector<vector<ll>>&adj){
        ll treesize = getsubtreesize(u,-1,adj);
        ll centroid = getcentroid(u,-1,treesize,adj);
        processcentroid(centroid,adj);
        removed[centroid] = true;
        for(auto v : adj[centroid]){
            if(!removed[v]) decompose(v,adj);
        }
    }
    ll solve(vector<vector<ll>>&adj){
        decompose(0,adj);
        return paths;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,k; cin >> n >> k;
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    CD cd(n,k);
    cout << cd.solve(adj);
}