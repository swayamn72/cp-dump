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
        ll n; cin >> n;
        map<ll,ll> mp;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res = 0;
        for(auto a : arr) mp[a]++;
        for(auto a : mp){
            if(a.second%2) res += a.first;
        }
        cout << res;
    }
} 