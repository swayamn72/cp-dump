#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<double>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll c1=0, c2=0, c3=0;
        for(auto a : arr){
            if(a==1) c1++;
            else if(a==2) c2++;
            else c3++;
        }
        vector<vector<vi>> dp(305,vector<vi>(305,vi(305)));
        for(ll k=0; k<=n; k++){
            for(ll j=0; j<=n; j++){
                for(ll i=0; i<=n; i++){
                    ll s = i+j+k;
                    if(s==0 || s>n) continue;
                    double expected = n;
                    if(i>0) expected += (double)i * dp[i-1][j][k];
                    if(j>0) expected += (double)j * dp[i+1][j-1][k];
                    if(k>0) expected += (double)k * dp[i][j+1][k-1];
                    dp[i][j][k] = expected/s;
                }
            }
        }
        cout << fixed << setprecision(9) << dp[c1][c2][c3];
    }
} 