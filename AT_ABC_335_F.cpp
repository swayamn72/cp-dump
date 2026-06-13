#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll b = sqrt(n) + 1;
    vi dp(n,0);
    vector<vector<ll>> lazy(b+1, vector<ll>(b+1,0));
    for(ll i=n-1; i>=0; i--){
        ll curr = 1;
        if(arr[i]>b){
            for(ll j=i+arr[i]; j<n; j+=arr[i]){
                curr = (curr + dp[j]) % mod;
            }
        }else{
            curr = (curr + lazy[arr[i]][i%arr[i]]) % mod;
        }
        dp[i] = curr;
        for(ll j=1; j<=b; j++){
            ll remainder = i%j;
            lazy[j][remainder] = (lazy[j][remainder] + dp[i]) % mod;
        }
    }
    cout << dp[0];
}