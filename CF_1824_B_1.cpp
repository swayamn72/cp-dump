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
ll modinv(ll a){
    return binexp(a,mod-2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<vector<ll>> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(k==1 || k==3){
            cout << 1 << "\n";
            continue;
        }
        ll total = 0;
        auto dfs = [&](auto &&self, ll u, ll p)->ll{
            ll size = 1;
            for(auto v : adj[u]){
                if(v==p) continue;
                ll subsize = self(self,v,u);
                ll ways = (subsize*(n-subsize))%mod;
                total = (total+ways)%mod;
                size += subsize;
            }
            return size;
        };
        dfs(dfs,0,-1);
        
        ll den = (n*(n-1))/2;
        ll num = (total+den)%mod;
        ll invden = modinv(den);
        cout << (num*invden)%mod;
    }
} 