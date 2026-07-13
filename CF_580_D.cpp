#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,k; cin >> n >> m >> k;
    vi arr(n); for(auto &x : arr) cin >> x;
    vector<vector<ll>> rules(n, vector<ll>(n,0));
    for(ll i=0; i<k; i++){
        ll x,y,c; cin >> x >> y >> c;
        x--; y--;
        rules[x][y] = c;
    }
    ll states = 1<<n;
    vector<vector<ll>> dp(states, vector<ll>(n,-1));
    for(ll i=0; i<n; i++){
        dp[1<<i][i] = arr[i];
    }
    ll res = 0;
    for(ll mask = 1; mask<states; mask++){
        ll bits = __builtin_popcount(mask);
        if(bits>m) continue;
        for(ll last=0; last<n; last++){
            if(dp[mask][last]==-1) continue;
            if(bits==m){
                res = max(res,dp[mask][last]);
                continue;
            }
            for(ll next=0; next<n; next++){
                if(!(mask&(1<<next))){
                    ll nextmask = mask | (1<<next);
                    ll ans = dp[mask][last] + arr[next] + rules[last][next];
                    dp[nextmask][next] = max(ans,dp[nextmask][next]);
                }
            }
        }
    }
    cout << res;
}