#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n1,n2,k1,k2; cin >> n1 >> n2 >> k1 >> k2;


        vector<vector<vi>> dp(n1+1,vector<vi>(n2+1,vi(2,0)));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        for(ll i=0; i<=n1; i++){
            for(ll j=0; j<=n2; j++){
                for(ll x=1; x<=k2; x++){
                    if(j+x<=n2){
                        dp[i][j+x][1] = (dp[i][j+x][1]+dp[i][j][0])%mod;
                    }
                }
                for(ll x=1; x<=k1; x++){
                    if(i+x<=n1){
                        dp[i+x][j][0] = (dp[i+x][j][0]+dp[i][j][1])%mod;
                    }
                }
            }
        }
        ll res = (dp[n1][n2][0]+dp[n1][n2][1])%mod;
        cout << res;
    }
}