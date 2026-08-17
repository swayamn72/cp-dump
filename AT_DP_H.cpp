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
        vector<vector<char>> grid(n,vector<char>(m));
        vector<vi> dp(n,vi(m,0));
        for(auto &a : grid) for(auto &b : a) cin >> b;
        dp[0][0] = 1;
        for(ll i=1; i<m; i++){
            if(grid[0][i]=='#') break;
            dp[0][i] = 1;
        }
        for(ll i=1; i<n; i++){
            if(grid[i][0]=='#') break;
            dp[i][0] = 1;
        }
        for(ll i=1; i<n; i++){
            for(ll j=1; j<m; j++){
                if(grid[i][j]=='#') continue;
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
        cout << dp[n-1][m-1];
    }
} 