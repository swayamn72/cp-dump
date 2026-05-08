#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;
    if(n==2){
        cout << abs(arr[1]-arr[0]);
        return 0;
    } 
    vector<ll> dp(n,0);
    dp[1] = abs(arr[1]-arr[0]);
    for(ll i=2; i<n; i++){
        dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout << dp[n-1];
}