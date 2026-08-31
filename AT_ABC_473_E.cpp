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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi dp(n+1,0);
        ll sum = 0;
        map<ll,ll> mp;
        mp[0] = 0;
        for(ll i=1; i<=n; i++){
            ll v = arr[i-1];
            sum += v;
            sum%=k;
            dp[i] = dp[i-1];
            if(mp.count(sum)){
                dp[i] = max(dp[i],1 + dp[mp[sum]]);
            }
            mp[sum] = i;
        }
        cout << dp[n];
    }
} 