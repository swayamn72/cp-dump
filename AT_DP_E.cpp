#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,weight; cin >> n >> weight;
    vector<pair<ll,ll>> arr(n); 
    ll valsum = 0;
    for(ll i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
        valsum += arr[i].second;
    }
    vector<ll> dp(valsum+1,1e12);
    dp[0] = 0;
    for(auto [w,v] : arr){
        for(ll i=valsum; i>=v; i--){
            dp[i] = min(dp[i],dp[i-v]+w); 
        }
    }
    ll res = 0;
    for(ll i=0; i<=valsum; i++){
        if(dp[i]<=weight){
            res = i;
        }
    }
    cout << res;
}