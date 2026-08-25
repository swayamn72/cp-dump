#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        vector<ll> dp(n);
        dp[0] = 0;
        if(n==1){
            cout << dp[0] << "\n";
            continue;
        }
        dp[1] = arr[1];
        for(ll i=2; i<n; i++){
            dp[i] = arr[i] + min(dp[i-1],dp[i-2]);
        }
        cout << dp[n-1] << "\n";
    }
    return 0;
}