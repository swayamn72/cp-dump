#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll h,n; cin >> h >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi c(n); for(auto &x : c) cin >> x;
        set<pair<ll,ll>> s; 
        for(ll i=0; i<n; i++) s.insert({1,i});
        
        ll res = 1;
        while(h>0){
            auto [time,index] = *s.begin();
            h -= a[index];
            res = time;
            s.erase(s.begin());
            s.insert({time+c[index],index});
        }
        cout << res << "\n";
    }
}