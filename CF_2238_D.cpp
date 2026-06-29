#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll maxn = 1e6+1;
    vi spf(maxn);
    for(ll i=1; i<maxn; i++) spf[i] = i;
    for(ll i=2; i<maxn; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<maxn; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    // for(auto a : spf) cout << a << " ";
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll,ll> mp;
        while(n!=1){
            mp[spf[n]]++;
            n/=spf[n];
        }
        ll total = 0;
        for(auto a : mp) total += a.second;
        cout << mp.size() + total - 1 << "\n";
    }
}