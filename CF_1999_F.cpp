#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
const int maxn = 2e5 + 5;
vector<ll> fact(maxn), invFact(maxn);
void factandinv(){
    fact[0] = 1;
    for(ll i=1; i<maxn; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    invFact[maxn-1] = binexp(fact[maxn-1],mod-2);
    for(int i=maxn-2; i>=0; i--){
        invFact[i] = (invFact[i+1]*(i+1))%mod;
    }
}
ll nCr(int n, int r){
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % mod)
            * invFact[n-r]) % mod;
}


ll binexp(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        b >>= 1;
        a = (a*a)%mod;
    }
    return res;
}
void factorials(vector<ll> &fact, vector<ll> &invfact){
    fact[0] = 1; int n = fact.size();
    for(ll i=1; i<n; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    invfact[n-1] = binexp(fact[n-1],mod-2);
    for(int i=n-2; i>=0; i--){
        invfact[i] = (invfact[i+1]*(i+1))%mod;
    }
}
ll ncr(ll n, ll r, vector<ll>&fact, vector<ll>&invfact){
    if(r<0 || r>n) return 0;
    return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> fact(2e5+1), invfact(2e5+1);
    factorials(fact,invfact);

    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll zeros = 0, ones = 0;
        for(auto a : arr){
            if(a==0) zeros++;
            else ones++;
        }
        ll res = 0;
        for(ll i=(k/2+1); i<=min(ones,k); i++){
            res += (ncr(ones,i,fact,invfact)*ncr(zeros,k-i,fact,invfact))%mod;
            res %= mod;
        }
        cout << res << "\n";
    }
}