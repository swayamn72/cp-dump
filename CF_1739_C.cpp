#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll mod = 998244353;
ll binexp(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll maxn = 70;
vi fact(maxn), invfact(maxn), alice(maxn), bob(maxn);
void factandinv(){
    fact[0] = 1;
    for(ll i=1; i<maxn; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    invfact[maxn-1] = binexp(fact[maxn-1],mod-2);
    for(ll i=maxn-2; i>=0; i--){
        invfact[i] = (invfact[i+1]*(i+1))%mod;
    }
}
ll ncr(ll n, ll r){
    if(r<0 || r>n) return 0;
    return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    factandinv();
    alice[2] = 1;
    bob[2] = 0;
    for(ll i=4; i<maxn; i+=2){
        alice[i] = (ncr(i-1,i/2-1) + bob[i-2]) % mod;
        bob[i] = (ncr(i,i/2)-alice[i]-1+mod)%mod;
    }
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << alice[n] << " " << bob[n] << " " << 1 << "\n";
    }
}