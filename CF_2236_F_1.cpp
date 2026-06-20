#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    ll maxn = 5e5+10;
    vi spf(maxn);
    for(ll i=0; i<maxn; i++) spf[i] = i;
    for(ll i=2; i*i<=maxn; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<maxn; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }


    ll t; cin >> t;
    while(t--){
        ll n,x; cin >> n >> x;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        for(auto &a : arr){
            while(a!=1){
                mp[spf[a]]++;
                a/=spf[a];
            }
        }
        ll res = 1;
        for(auto a : mp) res = (res*(a.second+1)) % mod;
        cout << res << "\n";
    }
}