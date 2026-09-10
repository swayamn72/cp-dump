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
        ll n = a.size(), m = b.size();
        vector<vi> dp(n+1,vi(m+1,0));
        for(ll j=0; j<=m; j++) dp[0][j] = j;
        for(ll i=0; i<=n; i++) dp[i][0] = i;
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        cout << dp[n][m];
    }
} 