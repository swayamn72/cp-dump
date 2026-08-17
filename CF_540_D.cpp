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
        ll r,s,p; cin >> r >> s >> p;
        vector<vector<vector<double>>> dp(r+1,vector<vector<double>>(s+1, vector<double>(p+1,0.0)));
        dp[r][s][p] = 1.0;
        for(ll i=r; i>=0; i--){ // rock
            for(ll j=s; j>=0; j--){ // scissor
                for(ll k=p; k>=0; k--){ // paper
                    double total = (i*j)+(j*k)+(i*k);
                    if(total==0) continue;
                    if(i>0 && j>0){
                        dp[i][j-1][k] += dp[i][j][k]*((i*j)/total);
                    }
                    if(j>0 && k>0){
                        dp[i][j][k-1] += dp[i][j][k] * ((k*j)/total);
                    }
                    if(i>0 && k>0){
                        dp[i-1][j][k] += dp[i][j][k] * ((i*k)/total);
                    }
                }
            }
        }
        double res1 = 0.0;
        for(ll i=1; i<=r; i++) res1 += dp[i][0][0];
        double res2 = 0.0;
        for(ll i=1; i<=s; i++) res2 += dp[0][i][0];
        double res3 = 0.0;
        for(ll i=1; i<=p; i++) res3 += dp[0][0][i];
        cout << fixed << setprecision(9) << res1 << " " << res2 << " " << res3;
        
    }
} 