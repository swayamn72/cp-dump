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
    cin >> t;
    while(t--){
        ll n,c; cin >> n >> c;
        vector<vi> arr;
        for(ll i=0; i<n; i++){
            ll l,r,x; cin >> l >> r >> x;
            arr.push_back({l,r,x});
        }        
        sort(arr.begin(),arr.end());
        set<ll> s; s.insert(c);
        for(auto &a : arr){
            ll l = a[0], r = a[1], c = a[2];
            auto it = s.lower_bound(l);
            if(it==s.end()) continue;
            if((*it)<=r) s.insert(a[2]);
        }
        // for(auto a : s) cout << a << " ";
        // cout << "\n";
        auto it = s.end(); it--;
        cout << *it << "\n";
    }
} 