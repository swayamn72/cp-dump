#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    vector<ll> arr(n); for(ll i=0; i<n; i++) cin >> arr[i];
	    ll sum = 0;
	    for(ll i=0; i<n; i++){
	        if(i%2==0) sum -= arr[i];
	        else sum += arr[i];
	    }
	    if(n%2==1 || sum>=0) cout << "YES" << "\n";
	    else cout << "NO" << "\n";
	}
}
