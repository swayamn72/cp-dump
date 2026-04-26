#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    ll res = LLONG_MAX;
    while(t--){
        ll n,a,b; cin >> n >> a >> b;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi prefsum(n); vi dp(n);
        partial_sum(arr.begin(),arr.end(),prefsum.begin());
        dp[0] = b*arr[0];
        for(ll i=1; i<n; i++){
            
        }
    }
}
// a - reposition
// b - conquer
// 5 6 3
// 1 5 6 21 30
// 1 6 12 33 63