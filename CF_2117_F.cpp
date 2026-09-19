#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
ll mulmod(ll a, ll b) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a);
        a = mulmod(a,a);
        b>>=1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }        
        ll leaves = 0;
        for(ll i=0; i<n; i++){
            if(adj[i].size()==1) leaves++;
        }
        if(adj[0].size()==1) leaves--;
        if(leaves>2){
            cout << 0 << "\n";
            continue;
        }
        if(leaves==1){
            cout << binexp(2,n) << "\n";
            continue;
        }
        ll one = -1, two = -1;
        for(ll i=1; i<n; i++){
            if(adj[i].size()==1){
                if(one==-1) one = i;
                else two = i;
            }
        }
        // cout << one << " " << two << "\n";
        vi depth(n), parent(n);
        auto dfs = [&](auto &&self, ll u, ll p, ll d)->void{
            parent[u] = p;
            depth[u] = d;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,d+1);
            }
        };
        dfs(dfs,0,-1,1);
        ll diff = abs(depth[one]-depth[two]);
        if(depth[one]<depth[two]) swap(one,two);
        while(depth[one]>depth[two]){
            one = parent[one];
        }
        ll lca = -1;
        while(one!=two){
            one = parent[one];
            two = parent[two];
        }
        ll num = 1;
        while(parent[one]!=-1){
            num++;
            one = parent[one];
        }
        if(diff==0){
            cout << binexp(2, num+1) << "\n";
            continue;
        }
        cout << (binexp(2, num)*((binexp(2, diff)+binexp(2, diff-1))%mod))%mod << "\n";
    }
} 