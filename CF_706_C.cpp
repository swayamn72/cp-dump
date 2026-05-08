#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;
    vector<string> v(n), rev(n); ll index = 0;
    for(auto &x : v){
        cin >> x;
        auto x1 = x; reverse(x1.begin(),x1.end());
        rev[index++] = x1;
    }
    vector<vector<ll>> dp(n, vector<ll>(2, LLONG_MAX));
    dp[0][0] = 0; dp[0][1] = arr[0];
    for(ll i=1; i<n; i++){
        if(v[i]>=v[i-1] && dp[i-1][0]!=LLONG_MAX){
            dp[i][0] = dp[i-1][0];
        }
        if(v[i]>=rev[i-1] && dp[i-1][1]!=LLONG_MAX){
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        }
        if(rev[i]>=v[i-1] && dp[i-1][0]!=LLONG_MAX){
            dp[i][1] = dp[i-1][0]+arr[i];
        }
        if(rev[i]>=rev[i-1] && dp[i-1][1]!=LLONG_MAX){
            dp[i][1] = min(dp[i][1], dp[i-1][1]+ arr[i]) ;
        }
    }
    ll res = min(dp[n-1][0], dp[n-1][1]);
    cout << (res==LLONG_MAX ? -1 : res) ;
}