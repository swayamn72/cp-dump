#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll INF = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll gcdv = arr[0];
        for(ll i=1; i<n; i++) gcdv = gcd(gcdv,arr[i]);
        ll count = 0;
        for(auto a : arr) if(a==gcdv) count++;
        if(count!=0){
            cout << n-count << "\n";
        }else{
            vector<ll> dp(5e3+5,INF);
            for(auto a : arr) dp[a] = 1;
            for(auto a : arr){
                for(ll i=1; i<=5000; i++){
                    ll newgcd = gcd(a,i);
                    dp[newgcd] = min(dp[newgcd],dp[i]+1);
                }
            }
            cout << dp[gcdv] + n - 2 << "\n";
        }
    }
}