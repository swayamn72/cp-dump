#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
// ll mod = 1e9+7;
// ll binexp(ll a, ll b) {
//     ll res = 1;
//     a%=mod;
//     while(b>0){
//         if(b&1) res = (res*a)%mod;
//         a = (a*a)%mod;
//         b>>=1;
//     }
//     return res;
// }
// ll maxn = 2e5+10;
// void factandinv(vector<ll> &fact, vector<ll> &invFact){
//     fact[0] = 1;
//     for(ll i=1; i<maxn; i++){
//         fact[i] = (fact[i-1]*i)%mod;
//     }
//     invFact[maxn-1] = binexp(fact[maxn-1],mod-2);
//     for(int i=maxn-2; i>=0; i--){
//         invFact[i] = (invFact[i+1]*(i+1))%mod;
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vector<ll> fact(maxn), invfact(maxn);
    // factandinv(fact,invfact);
    // auto ncr = [&](ll n, ll r)->ll{
    //     if(r < 0 || r > n) return 0;
    //     return (((fact[n] * invfact[r]) % mod)
    //         * invfact[n-r]) % mod;
    // }; 
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m,h; cin >> n >> m >> h;   
        vi arr(m); for(auto &x : arr) cin >> x;
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        if(sum<n){
            cout << -1;
            continue;
        }
        ll totalleft = sum-1;
        ll otherdepleft = sum-arr[h-1];
        ll teamleft = n-1;
        if(otherdepleft<teamleft){
            cout << 1;
            continue;
        }
        double prob = 1.0;
        for(ll i=0; i<teamleft; i++){
            prob *= (double) (otherdepleft-i) / (double)(totalleft-i);
        }
        cout << fixed << setprecision(6) << 1.0 - prob;
    }
} 