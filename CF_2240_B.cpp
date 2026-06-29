#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll mod = 998244353;
ll binexp(ll a, ll b){
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
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,m,r,c; cin >> n >> m >> r >> c;
        if(r==1 && c==1){
            cout << 1 << "\n";
            continue;
        }
        ll top = (r-1);
        ll left = (c-1);
        ll total = m*top + n*left - top*left;
        cout << binexp(2,total) << "\n";
    }
}