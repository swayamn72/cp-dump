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
        string a,b; cin >> a >> b;
        ll n = a.size();
        ll target = 0;
        for(auto x : a){
            target += (x=='+') ? 1 : -1;
        }
        vector<vector<double>> dp(n+1,vector<double>(25,0.0));
        ll offset = 10;
        dp[0][offset] = 1.0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<=20; j++){
                if(dp[i][j]==0.0) continue;
                if(b[i]=='+'){
                    dp[i+1][j+1] += dp[i][j];
                }else if(b[i]=='-'){
                    dp[i+1][j-1] += dp[i][j];
                }else{
                    dp[i+1][j+1] += 0.5*dp[i][j];
                    dp[i+1][j-1] += 0.5*dp[i][j];
                }
            }
        }
        cout << fixed << setprecision(9) << dp[n][target+offset];
    }
} 