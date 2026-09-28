#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vector<vi> dp(n+1,vi(m+1,0));
        for(ll j=1; j<=m; j++) dp[1][j] = 1;
        // dp[i][j] = no. of ways to form n numbers with nth number j 
        for(ll i=2; i<=n; i++){
            vi pref(m+1);
            pref[0] = dp[i-1][0];
            for(ll j=1; j<=m; j++) pref[j] = (pref[j-1]+dp[i-1][j])%mod;
            
            for(ll j=1; j<=m; j++){
                if(k==0){
                    dp[i][j] = pref[m];
                }else{
                    ll ans = 0;
                    ll left = j-k;
                    if(left>=1) ans = (ans + pref[left])%mod;
                    ll right = j+k;
                    if(right<=m) ans = (ans+pref[m]-pref[right-1]+mod)%mod;
                    dp[i][j] = ans;
                }
                
            }
        }
        ll res = 0;
        for(ll i=0; i<=m; i++) res = (res + dp[n][i])%mod;
        cout << res;
    }
}