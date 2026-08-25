#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
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
        ll n; cin >> n;
        ll res = 0;
        map<ll,ll> mp;
        ll inv5 = modinv(5);
        auto dfs = [&](auto &&self, ll x)->ll{
            if(x==n) return 1;
            if(n%x!=0) return 0;
            if(mp.count(x)) return mp[x];
            ll sum = 0;
            for(ll i=2; i<=6; i++){
                sum = (sum + self(self,x*i)) % mod;
            }
            return mp[x] = (sum*inv5)%mod;
        };
        cout << dfs(dfs,1);
    }
} 