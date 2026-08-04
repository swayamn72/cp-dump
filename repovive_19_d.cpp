#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    vector<vector<ll>> adj(n);
    vi degree(n), blocking(n);
    for(ll i=0; i<n-1; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=0; i<n; i++){
        degree[i] = adj[i].size();
        for(auto v : adj[i]){
            if(arr[v]<=arr[i]) blocking[i]++;
        }
    }
    auto bad = [&](ll x, ll p)->ll{
        if(p==-1){
            if(degree[x]>=1 && blocking[x]==0) return 1;
            return 0;
        }else{
            if(degree[x]>=2){
                ll blockingchild = blocking[x];
                if(arr[p]<=arr[x]) blockingchild--;
                if(blockingchild==0) return 1;
            }
            return 0;
        }
    };
    ll unhappy = 0;
    auto dfs1 = [&](auto &&self, ll u, ll p)->void{
        unhappy += bad(u,p);
        for(auto v : adj[u]){
            if(v!=p) self(self,v,u);
        }
    };
    dfs1(dfs1,0,-1);
    ll minv = unhappy;
    ll count = 1;
    auto dfs2 = [&](auto &&self, ll u, ll p, ll fu)->void{
        for(auto v : adj[u]){
            if(v==p) continue;
            ll fv = fu - bad(u,-1) - bad(v,u) + bad(u,v) + bad(v,-1);
            if(fv<minv){
                minv = fv;
                count = 1;
            }else if(fv==minv){
                count++;
            }
            self(self,v,u,fv);
        }
    };
    dfs2(dfs2,0,-1,unhappy);
    cout << minv << " " << count;
}