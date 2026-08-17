#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b; cin >> a >> b;
    ll n = a.size(), m = b.size();
    vector<vi> dir(n+1, vi(m+1,0));
    vector<vi> dp(n+1, vi(m+1,0));
    // 0 - up  1 - left  2 - cross
    for(ll i=1; i<=m; i++) dir[0][i] = 1; 
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                dir[i][j] = 2;
            }else{
                dp[i][j] = dp[i-1][j];
                if(dp[i][j-1]>dp[i][j]){
                    dp[i][j] = dp[i][j-1];
                    dir[i][j] = 1;
                }
            }
        }
    }
    string res = "";
    ll u = n, v = m;
    while(u!=0 && v!=0){
        ll curdirr = dir[u][v];
        if(curdirr==2){
            res += a[u-1];
            u--; v--;
        }else if(curdirr==1){
            v--;
        }else{
            u--;
        }
    }
    reverse(res.begin(),res.end());
    cout << res;
}