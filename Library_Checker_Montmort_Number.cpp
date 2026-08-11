#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll binexp(ll a, ll b, ll mod){
    a%=mod;
    ll res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,mod; cin >> n >> mod;
    vector<ll> fact(n+1); fact[0] = fact[1] = 1;
    for(ll i=2; i<=n; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    vi invfact(n+1);
    invfact[n] = binexp(fact[n],mod-2,mod);
    auto ncr = [&](ll n, ll r){
        ll res = fact[n];
        res = (res*invfact[r])%mod;
        res = (res*invfact[n-r])%mod;
    };
    ll res = fact[n];
    ll sum = 0;
    for(ll i=0; i<=n; i++){
        ll toadd = invfact[i];
        if(i%2) toadd = -toadd;
        sum = (sum+toadd)%mod;

    }
    
}