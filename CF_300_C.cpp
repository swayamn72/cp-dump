#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll mod = 1e9+7;
ll mulmod(ll a, ll b) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b) {
    ll mod = 1e9+7;
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a);
        a = mulmod(a,a);
        b>>=1;
    }
    return res;
}
ll maxn = 1e6+5;
vi fact(maxn), invFact(maxn);
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
ll ncr(int n, int r){
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % mod)
            * invFact[n-r]) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    factandinv();
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll a,b,n; cin >> a >> b >> n;
    ll res = 0;
    for(ll i=0; i<=n; i++){
        ll num = a*i + b*(n-i);
        bool flag = true;
        while(num>0){
            ll digit = num%10;
            if(digit!=a && digit!=b){
                flag = false;
                break;
            }
            num/=10;
        }
        if(!flag) continue;
        res = (res+ncr(n,i))%mod;
    }
    cout << res << "\n";
}