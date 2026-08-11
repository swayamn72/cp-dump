#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
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
ll inv(ll a, ll mod){
    return binexp(a,mod-2,mod);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<vector<ll>> arr(n);
    vi count(1e6+1,0);
    for(ll i=0; i<n; i++){
        ll k; cin >> k;
        for(ll j=0; j<k; j++){
            ll x; cin >> x;
            arr[i].push_back(x);
            count[x]++;
        }
    }
    ll res = 0;
    ll invn = inv(n,mod);
    ll invn2 = inv(n*n,mod);

    for(ll i=0; i<n; i++){
        ll sum = 0;
        for(auto a : arr[i]){
            // kids who want that gift
            sum = (sum+count[a])%mod;
        }
        ll invk = inv(arr[i].size(),mod);

        ll val = (sum*invk)%mod;
        val = (val*invn2)%mod;

        res = (res+val)%mod;
    }
    cout << res;
}