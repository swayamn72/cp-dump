#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll mod = 998244353;
ll mulmod(ll a, ll b, ll mod) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b, ll mod) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a,mod);
        a = mulmod(a,a,mod);
        b>>=1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        for(ll i=0; i<n; i++) if(a[i]>b[i]) swap(a[i],b[i]);
        if(!is_sorted(a.begin(),a.end()) || !is_sorted(b.begin(),b.end())){
            cout << 0 << "\n";
            continue;
        }        
        ll k = 0;
        for(ll i=0; i<n-1; i++){
            if(b[i]>a[i+1])k++;
        }
        cout << binexp(2,n-k,mod) << "\n";
    }
}