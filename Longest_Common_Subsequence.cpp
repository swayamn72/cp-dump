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
        vi a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        vector<vi> dp(n+1,vi(m+1,0));
        // 0-left 1-up 2-diag
        vector<vi> dir(n+1,vi(m+1,0));

        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                dp[i][j] = dp[i][j-1];
                if(a[i-1]==b[j-1]){
                    dir[i][j] = 2;
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    if(dp[i-1][j]>dp[i][j]){
                        dir[i][j] = 1;
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        vi res;
        ll i = n, j = m;
        while(i>0 && j>0){
            ll curdir = dir[i][j];
            if(curdir==2){
                res.push_back(a[i-1]);
                i--; j--;
            }else if(curdir==1){
                i--;
            }else{
                j--;
            }
        }
        reverse(res.begin(),res.end());
        cout << res.size() << "\n";
        for(auto x : res) cout << x << " ";
    }
} 