#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll n;
double solve(ll c1, ll c2, ll c3, vector<vector<vector<double>>> &dp){
    if(c1==0 && c2==0 && c3==0) return 0.0;
    if(dp[c1][c2][c3]!=-1.0) return dp[c1][c2][c3];
    double res = n;
    if(c1>0) res += c1 * solve(c1-1,c2,c3,dp);
    if(c2>0) res += c2 * solve(c1+1,c2-1,c3,dp);
    if(c3>0) res += c3 * solve(c1,c2+1,c3-1,dp);
    res /= (c1+c2+c3);
    return dp[c1][c2][c3] = res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(n+1, -1.0)));
    ll c1 = 0, c2 = 0, c3 = 0;
    for(auto a : arr){
        if(a==1) c1++;
        else if(a==2) c2++;
        else c3++;
    }
    cout << setprecision(15) << solve(c1,c2,c3,dp);
}