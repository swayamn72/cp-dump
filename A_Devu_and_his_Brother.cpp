#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        set<ll> s; for(auto x : a) s.insert(x); for(auto x : b) s.insert(x);
        sort(a.begin(),a.end());
        vi pref(n,0); pref[0] = a[0];
        for(ll i=1; i<n; i++) pref[i] = a[i] + pref[i-1];
        ll res = LLONG_MAX;
        for(auto x : s){
            
        }
    }
} 