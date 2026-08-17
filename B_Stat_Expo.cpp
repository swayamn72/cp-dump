#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        vector<vector<ll>> dp(9,vector<ll>(5,0));
        for(ll i=0 ; i<=8; i++) dp[i][0] = 1;
        for(ll i=1; i<=8; i++){
            for(ll j=1; j<=4; j++){
                if(j*2>i) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        cout << 10;
    }
} 