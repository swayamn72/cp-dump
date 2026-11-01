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
        ll n,m; cin >> n >> m;
        vi arr = {m+2};
        ll val = m+2;
        while(val>2){
            val -= (val-1)/2;
            arr.push_back(val);
        }
        // for(auto a : arr) cout << a << " ";
        // cout << "\n";
        if(arr.size()>n){
            cout << 0 << "\n";
            continue;
        }
        vi ansarr;
        ll s = arr.size();
        ll res = 0;
        for(ll i=s; i<=n; i++){ // 4 to 6 
            ll ans = ncr(i-1,s-1); // 
            ans = (ans*(n-i+1))%mod;
            ansarr.push_back(ans);
            res = (res+ans)%mod;
        }
        // 3 8 10
        // for(auto a : ansarr) cout << a << " ";
        // cout << "\n";
        
        cout << res << "\n";
    }
}