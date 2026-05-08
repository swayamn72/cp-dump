#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,weight; cin >> n >> weight;
    vector<pair<ll,ll>> arr(n); 
    for(ll i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    vector<vector<ll>> dp(n, vector<ll>(weight+1,0LL));
    for(int i=0; i<=weight; i++){
        if(arr[0].first <= i) dp[0][i] = arr[0].second;
    }
    for(int i=1; i<n; i++){
        auto [w,v] = arr[i];
        for(int j=1; j<=weight; j++){
            dp[i][j] = dp[i-1][j];
            if(j-w>=0) dp[i][j] = max(dp[i][j],dp[i-1][j-w]+v);
        }
    }
    cout << dp[n-1][weight];
}