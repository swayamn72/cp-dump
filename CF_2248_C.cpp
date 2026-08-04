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
        ll n; cin >> n; n*=2;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        vi dp(n);
        dp[0] = 1;
        mp[arr[0]] = 0;

        for(ll i=1; i<n; i++){
            if(mp.find(arr[i])==mp.end()){
                dp[i] = dp[i-1]+1;
                mp[arr[i]] = i;
            }else{
                ll idx = mp[arr[i]];
                dp[i] = dp[i-1]+1;

                ll ans = (i-idx+1)*(i-idx+1);
                if(idx>0) ans += dp[idx-1];
                dp[i] = max(dp[i],ans);
            }
        }
        cout << dp[n-1] << "\n";
    }
}