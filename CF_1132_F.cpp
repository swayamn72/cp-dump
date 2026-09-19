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
        ll n; cin >> n;
        string s; cin >> s;
        vector<vi> dp(n,vi(n,0));
        for(ll i=0; i<n; i++) dp[i][i] = 1;
        for(ll len=2; len<=n; len++){
            for(ll i=0; i<=n-len; i++){
                ll l = i, r = i+len-1;
                dp[l][r] = 1 + dp[l+1][r];
                for(ll k=l+1; k<=r; k++){
                    if(s[l]==s[k]){
                        ll middlecost = (k>l+1 ? dp[l+1][k-1] : 0);
                        ll rightcost = dp[k][r];
                        dp[i][r] = min(dp[l][r],middlecost+rightcost); 
                    }
                }
            }
        }
        cout << dp[0][n-1];
    }
} 