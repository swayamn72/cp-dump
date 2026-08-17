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
        ll w,b; cin >> w >> b;
        ll total = w+b;
        ll rem = total%3;
        double res = 0.0;
        vector<vector<double>> dp(w+1,vector<double>(b+1,0.0));
        dp[w][b] = 1.0;
        for(ll i=w; i>=0; i--){
            for(ll j=b; j>=0; j--){
                if(i==0 && j==0) continue;
                ll curr = (i+j)%3;
                if(curr==rem){
                    double prob = dp[i][j] * ((double)i/(double)(i+j));
                    res += prob;
                    double prob2 = dp[i][j] * ((double)j/(double)(i+j));
                    if(j>0) dp[i][j-1] += prob2;
                }else if(curr==((rem-1+3)%3)){
                    double prob2 = dp[i][j] * ((double)j/(double)(i+j));
                    if(j>0) dp[i][j-1] += prob2;
                }else{
                    double prob = dp[i][j] * ((double)i/(double)(i+j));
                    if(i>0) dp[i-1][j] += prob;
                    double prob2 = dp[i][j] * ((double)j/(double)(i+j));
                    if(j>0) dp[i][j-1] += prob2;
                }
            }
        }
        cout << fixed << setprecision(9) << res;
    }
} 