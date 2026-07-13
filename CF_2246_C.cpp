#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
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
    vi fact(maxn), invfact(maxn);
    factandinv(fact,invfact);
    auto ncr = [&](ll n, ll r)->ll{
        if(r < 0 || r > n) return 0;
        return (((fact[n] * invfact[r]) % mod)
            * invfact[n-r]) % mod;
    };  
    auto evenways = [&](ll k)->ll{
        if(k==0) return 1;
        ll ways = 0;
        for(ll i=0; i<=k; i+=2){
            ways = (ways+ncr(k,i))%mod;
        }
        return ways;
    };
    auto oddways = [&](ll k)->ll{
        if(k==0) return 0;
        ll ways = 0;
        for(ll i=1; i<=k; i+=2){
            ways = (ways+ncr(k,i))%mod;
        }
        return ways;
    };
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        ll count = 0;
        for(auto a : arr){
            if(a==-1) count++;
            else mp[a]++;
        } 
        ll evenminus1 = evenways(count);
        ll oddminus1 = oddways(count);
        // cout << evenminus1 << " " << oddminus1 << "\n";
        ll zeros = 1;
        for(auto a : mp){
            zeros = (zeros*evenways(a.second))%mod;
        }
        ll res = (evenminus1*zeros)%mod;
        ll pairs = 0;
        for(auto a : mp){
            if(mp.count(a.first+1)){
                pairs++;
            }
        }
        ll pways = (((oddminus1*pairs)%mod)*(zeros))%mod;
        // cout << pways << "\n";
        res = (res+pways)%mod;
        cout << res << "\n";
    }
}
// -1 1 2 3  . . . .
// -1 3 4 , -1 k k+1