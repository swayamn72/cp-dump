#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;
    
    vector<vector<ll>> dp(n, vector<ll>(3,-1));
    dp[0][0] = 0;
    if(arr[0]==1 || arr[0]==3) dp[0][1] = 1;
    if(arr[0]==2 || arr[0]==3) dp[0][2] = 1;

    for(ll i=1; i<n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        if(arr[i]==1 || arr[i]==3){
            dp[i][1] = max(dp[i-1][0],dp[i-1][2])+1;
        }
        if(arr[i]==2 || arr[i]==3){
            dp[i][2] = max(dp[i-1][0],dp[i-1][1])+1;
        }
    }
    ll res = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << n-res;
}
