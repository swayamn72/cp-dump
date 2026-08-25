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
        ll n,a,b; cin >> n >> a >> b;
        vector<vector<double>> dp(n+1,vector<double>(6*n+1,0.0));
        dp[0][0] = 1.0;
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=6*n; j++){
                for(ll k=1; k<=6; k++){
                    if((j-k)>=0){
                        dp[i][j] += dp[i-1][j-k]/6.0;
                    }
                }
            }
        }
        double res = 0.0;
        for(ll i=a; i<=b; i++){
            res += dp[n][i];
        }
        cout << fixed << setprecision(6) << res;
    }
} 