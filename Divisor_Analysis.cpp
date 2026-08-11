#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
ll binexp(ll a, ll b){
    a%=mod;
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
    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for(ll i=0; i<n; i++){
        ll x,k; cin >> x >> k;
        v.push_back({x,k});
    }
    // count
    ll count = 1;
    for(auto [a,b] : v){
        count = (count*(b+1))%mod;
    }

    // sum
    ll sum = 1;
    for(auto [x,k] : v){
        ll num = (binexp(x,k+1)-1+mod)%mod;
        ll den = binexp(x-1,mod-2);
        ll val = (num*den)%mod;
        sum = (sum*val)%mod;
    }

    // product
    


    cout << count << " " << sum << " ";
}