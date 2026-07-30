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
ll maxn = 3e5+10;
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
    vi fact(maxn), invfact(maxn);
    factandinv(fact,invfact);
    auto ncr = [&](ll n, ll r)->ll{
        if(r < 0 || r > n) return 0;
        return (((fact[n] * invfact[r]) % mod)
            * invfact[n-r]) % mod;
    };
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll res = 1;
    for(ll i=0; i<n; i+=3){
        ll minv = min({arr[i],arr[i+1],arr[i+2]});
        ll count = 0;
        if(arr[i]==minv) count++;
        if(arr[i+1]==minv) count++;
        if(arr[i+2]==minv) count++;
        res = (res*count)%mod;
    }
    res = (res * ncr(n/3,n/6))%mod;
    cout << res << "\n";
}