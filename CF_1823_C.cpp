#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> primefactors(ll n){
    vector<ll> res;
    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            res.push_back(i);
            n /= i;
        }
    }
    if(n>1) res.push_back(n);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n); for(ll i = 0; i < n; i++) cin >> a[i];
        map<ll,ll> mp;
        for(ll i=0; i<n; i++){
            vector<ll> ans = primefactors(a[i]);
            for(auto a : ans) mp[a]++;
        }
        ll res = 0;
        for(auto &a : mp){
            res += a.second/2;
            a.second %= 2;
        }
        ll val = 0;
        for(auto a : mp) if(a.second) val++;
        res += val/3;
        cout << res << "\n";
    }
}