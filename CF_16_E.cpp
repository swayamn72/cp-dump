#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<vector<double>> mat(n, vector<double>(n));
    for(auto &a : mat) for(auto &b : a) cin >> b;

    ll m = 1<<n;
    vector<double> dp(m,0.0);
    dp[m-1] = 1.0;
    for(ll mask=m-1; mask>0; mask--){
        ll k = __builtin_popcountll(mask);
        if(k==1) continue;
        double pairs = (k * (k-1))/2.0;
        for(ll i=0; i<n; i++){
            if(mask&(1<<i)){
                for(ll j=i+1; j<n; j++){
                    if(mask&(1<<j)){
                        dp[mask^(1<<j)] += (dp[mask] * mat[i][j])/pairs;
                        dp[mask^(1<<i)] += (dp[mask] * mat[j][i])/pairs;
                    }
                }
            }
        }
    }
    for(ll i=0; i<n; i++){
        cout << fixed << setprecision(6) << dp[1<<i] << " ";
    }
}