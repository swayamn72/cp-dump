#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
ll mulmod(ll a, ll b, ll mod) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b, ll mod) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a,mod);
        a = mulmod(a,a,mod);
        b>>=1;
    }
    return res;
}
ll modinv(ll a, ll mod){
    return binexp(a,mod-2,mod);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,a,b,p,q; cin >> n >> a >> b >> p >> q;
        vector<vi> dpa(n+1,vi(n+1,0));
        vector<vi> dpt(n+1,vi(n+1,0));
        for(ll i=1; i<=n; i++){
            dpt[n][i] = 1;
            dpa[n][i] = 1;
        }
        ll invp = modinv(p,mod), invq = modinv(q,mod);
        for(ll i=n-1; i>=1; i--){
            for(ll j=n-1; j>=1; j--){
                ll expt = 0;
                for(ll k=1; k<=p; k++){
                    ll nexti = min(i+k,n);
                    expt = (expt+dpa[nexti][j]) % mod;
                }
                
            }
        }
    }
} 