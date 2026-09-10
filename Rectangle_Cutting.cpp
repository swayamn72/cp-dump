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
        ll a,b; cin >> a >> b;
        vector<vi> dp(a+1,vi(b+1,1e9));
        for(ll i=1; i<=a; i++){
            for(ll j=1; j<=b; j++){
                if(i==j){
                    dp[i][j] = 0;
                    continue;
                }
                for(ll k=1; k<i; k++){
                    dp[i][j] = min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                }
                for(ll k=1; k<j; k++){
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
        cout << dp[a][b];
    }
} 