#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;
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
ll maxn = 40;
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
ll dp[200000][31][2];
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
        ll n; cin >> n;
        vector<vi> adj(n);
        for(ll i=0; i<n-1; i++){
            ll u,v; cin >> u >> v; 
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }       
        ll k; cin >> k;
        vector<pair<ll,ll>> arr(k);
        for(auto &x : arr){
            cin >> x.first >> x.second;
        }
        ll maxe = n;
        maxe = min(maxe,30LL);
        // vector<vector<vi>> dp(n,vector<vi>(maxe+1,vi(2,0)));
        // dp[u][j][0]  ways to chose set of size j in subtree of u , not picking u
        // dp[u][j][1]  picking u

        for(ll i=0; i<n; i++){
            for(ll j=0; j<=maxe; j++){
                for(ll k=0; k<2; k++){
                    dp[i][j][k] = 0;
                }
            }
        }

        auto dfs = [&](auto &&self, ll u, ll p)->void{
            dp[u][0][0] = dp[u][1][1] = 1;
            for(auto v : adj[u]){
                if(v==p) continue;
                self(self,v,u);
                vector<vi> nextdp(maxe+1,vi(2,0));

                // combine dp[u] and dp[v]
                for(ll j=0; j<=maxe; j++){
                    if(dp[u][j][0]==0 && dp[u][j][1]==0) continue;
                    for(ll k=0; j+k<=maxe; k++){
                        if(dp[v][k][0]==0 && dp[v][k][1]==0) continue;

                        ll waysvany = (dp[v][k][0]+dp[v][k][1])%mod;
                        nextdp[j+k][0] = (nextdp[j+k][0] + dp[u][j][0]*waysvany)%mod;
                        
                        nextdp[j+k][1] = (nextdp[j+k][1] + dp[u][j][1]*dp[v][k][0])%mod;
                    }
                }
                for(ll j=0; j<=maxe; j++){
                    dp[u][j][0] = nextdp[j][0];
                    dp[u][j][1] = nextdp[j][1];
                }
            }
        };
        dfs(dfs,0,-1);

        vi nums(maxe+1,0); // nums[i] = total sets of size i in the tree
        for(ll i=1; i<=maxe; i++){
            nums[i] = (dp[0][i][0]+dp[0][i][1])%mod;
        }

        ll res = 1;
        for(auto [p,e] : arr){
            ll ans = 0;
            for(ll i=1; i<=min(maxe,e); i++){
                if(!nums[i]) continue;
                ll ways = ncr(e-1,i-1);
                ans = (ans + nums[i]*ways)%mod;
            }
            res = (res*ans)%mod;
        }
        cout << res << "\n";
    }
}