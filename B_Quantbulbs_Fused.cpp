#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n = 1e6+5;
    vector<double> dp(n,0.0);
    for(ll i=1; i<n; i++){
        dp[i] = (1.0/i) + dp[i-1];
    }
    ll t=1; 
    cin >> t;
    while(t--){
        ll x; cin >> x;
        cout << floor(dp[x]) << "\n";
    }
} 