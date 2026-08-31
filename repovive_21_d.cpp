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
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        ll minv = LLONG_MAX, maxv = LLONG_MIN;
        for(ll i=0; i<n; i++){
            ll dist = i - arr[i];
            
        }
    }
} 