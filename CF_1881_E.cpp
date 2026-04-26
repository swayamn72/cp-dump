#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll t; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    vector<ll> arr(n); for(ll i=0; i<n; i++) cin >> arr[i];
	    vector<ll> dp(n+1, 0);
	    dp[n] = 0;
	    for(ll i=n-1; i>=0; i--){
	        ll index = i+arr[i];
	        if(index>=n){
	            dp[i] = n-i;
	        }else{
	            dp[i] = dp[index+1];
	        }
	        ll val2 = 1 + dp[i+1];
	        dp[i] = min(dp[i], val2);
	    }
	    cout << dp[0] << endl;
	}
}