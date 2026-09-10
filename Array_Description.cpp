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
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<vi> dp(n,vi(m+2,0));
        if(!arr[0]){
            for(ll v=1; v<=m; v++) dp[0][v] = 1;
        }else{
            dp[0][arr[0]] = 1;
        }
        for(ll i=1; i<n; i++){
            if(arr[i]==0){
                for(ll v=1; v<=m; v++){
                    dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1])%mod;
                }
            }else{
                ll v = arr[i];
                dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1])%mod;
            }
        }
        ll res = 0;
        for(ll v=1; v<=m; v++){
            res = (res + dp[n-1][v])%mod;
        }
        cout << res;
    }
} 