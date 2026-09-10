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
    cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        vector<vi> dp(n+1,vi(7,1e9));
        dp[0][3] = 0;
        for(ll i=1; i<=n; i++){
            char ch = s[i-1];
            for(ll j=0; j<7; j++){
                for(ll k=0; k<7; k++){
                    if(j==k) continue;
                    ll sum = k-3;
                    if(ch=='+' && sum<=0) continue;
                    if(ch=='-' && sum>=0) continue;
                    if(ch=='0' && sum!=0) continue;
                    if(dp[i-1][j]!=1e9){
                        dp[i][k] = min(dp[i][k],max(dp[i-1][j],abs(j-k)));
                    } 
                }
            }
        }
        ll res = 1e9;
        for(ll i=0; i<7; i++) res = min(res,dp[n][i]);
        cout << (res==1e9 ? -1 : res) << "\n";        
    }
} 