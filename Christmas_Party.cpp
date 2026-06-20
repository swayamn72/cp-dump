#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll maxn = 1e6+5;
    ll mod = 1e9+7;
    vi fact(maxn);
    vi invfact(maxn);
    auto binexp = [&](ll a, ll b){
        ll res = 1;
        while(b>0){
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b>>=1;
        }
        return res;
    };
    auto modinverse = [&](ll n){
        return binexp(n,mod-2);
    };
    auto precompute = [&](){
        fact[0] = 1;
        invfact[0] = 1;
        for(ll i=1; i<maxn; i++){
            fact[i] = (fact[i-1]*i)%mod;
        }
        invfact[maxn-1] = modinverse(fact[maxn-1]);
        for(ll i=maxn-2; i>=1; i--){
            invfact[i] = (invfact[i+1]*(i+1))%mod;
        }
    };
    precompute();
    auto ncr = [&](ll n, ll r)->ll{
        if(r<0 || r>n) return 1;
        ll num = fact[n];
        ll den = (invfact[r]*invfact[n-r])%mod;
        return (num*den)%mod;
    };
    
    ll n; cin >> n;
    bool flag = false;
    ll res = fact[n];
    for(ll i=1; i<=n; i++){
        ll val = (ncr(n,i) * fact[n-i])%mod;
        if(!flag) res = (res-val+mod)%mod;
        else res = (res+val) % mod;
        flag = !flag;
    }
    cout << res;
}