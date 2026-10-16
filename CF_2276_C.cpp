#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        vi pref(n+1); pref[0] = 0;
        for(ll i=1; i<=n; i++) pref[i] = pref[i-1] + arr[i-1];

        ll res = 0;
        map<ll,ll> mp;
        for(ll i=1; i<=n; i++){
            if(i-k-1>=0) mp[(pref[i-k-1])%k]++;
            res += mp[pref[i]%k];
        }
        cout << res << "\n";
    }
}