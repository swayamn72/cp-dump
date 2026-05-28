#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353;
const int maxn = 105; 
ll fact[maxn], invFact[maxn];
ll mulmod(ll a, ll b, ll mod) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}
void factandinv(){
    fact[0] = 1;
    for(ll i=1; i<maxn; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    invFact[maxn-1] = binexp(fact[maxn-1], mod-2, mod);
    for(int i=maxn-2; i>=0; i--){
        invFact[i] = (invFact[i+1]*(i+1))%mod;
    }
}
ll ncr(int n, int r){
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % mod) * invFact[n-r]) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);\
    factandinv();
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll buffer; cin >> buffer;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll sum = accumulate(arr.begin(),arr.end(),0LL); sum += buffer;
        bool flag = true;
        ll div = sum/n, rem = sum%n;
        ll negsum = 0;
        for(auto &x : arr){
            if(x>div+1){
                flag = false;
                break;
            }
            x -= div;
            if(x<0) negsum += abs(x);
        }
        ll ones = 0;
        for(auto &x : arr) if(x==1) ones++;
        if(negsum > buffer) flag = false;
        if(ones > rem) flag = false;
        if(!flag){
            cout << 0 << "\n";
            continue;
        }
        ll rembuffer = buffer - negsum;
        
        ll res = ncr(n-ones,rem-ones);
        res = (res * fact[rem]) % mod;
        res = (res * fact[n - rem]) % mod;
        cout << res << "\n";
    }
}
// 6   4  2  1  1
// 6   1 -1 -2 -2
// 1   1  0  0  0