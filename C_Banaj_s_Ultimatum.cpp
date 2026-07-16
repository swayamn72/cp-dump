#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;        
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        ll xorsum = 0;
        for(auto a : arr) xorsum ^= a;
        // cout << xorsum << "\n";
        map<ll,ll> mp;
        for(auto a : arr) mp[a]++;
        ll res = 0;
        ll single = 0;
        for(auto a : mp){
            if(a.first==0) continue;
            res += (a.second)/2;
            if(a.second%2){
                single++;
            }
        }
        ll pairs = (single+1)/2;
        res += (pairs*2);
        cout << res << "\n";
    }
}