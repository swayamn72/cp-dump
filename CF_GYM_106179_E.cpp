#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
ll binexp(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll maxn = 2e5+10;
void factandinv(vector<ll> &fact, vector<ll> &invFact){
    fact[0] = 1;
    for(ll i=1; i<maxn; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    invFact[maxn-1] = binexp(fact[maxn-1],mod-2);
    for(int i=maxn-2; i>=0; i--){
        invFact[i] = (invFact[i+1]*(i+1))%mod;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> fact(maxn), invfact(maxn);
    factandinv(fact,invfact);
    auto ncr = [&](ll n, ll r)->ll{
        if(r < 0 || r > n) return 0;
        return (((fact[n] * invfact[r]) % mod)
            * invfact[n-r]) % mod;
    }; 

    ll t=1; 
    cin >> t;
    while(t--){
        ll n,c; cin >> n >> c;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi depth(n,0);
        auto dfs = [&](auto &&self, ll u, ll p, ll d)->void{
            depth[u] = d;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u,d+1);
            }
        };
        dfs(dfs,0,-1,0);
        auto solve = [&](ll k)->ll{
            if(k>=n) return 0;
            ll res = 0;
            for(ll i=1; i<n; i++){
                res = (res + ncr(depth[i]-1,k-1))%mod;
            }
            res = (res*binexp(2,k-1))%mod;
            res = (res*fact[n-k-1])%mod;
            return res;
        };
        ll res = (solve(c)-solve(c+1)+mod)%mod;
        cout << res << "\n";
    }
} 