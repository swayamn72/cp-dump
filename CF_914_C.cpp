#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll k; cin >> k;
    if(k==0){
        cout << 1;
        return 0;
    }
    ll len = s.size();
    vi steps(len+1,0);
    for(ll i=2; i<=len; i++){
        steps[i] = steps[__builtin_popcountll(i)] + 1;
    }
    vector<vector<vector<ll>>> dp(len+1, vector<vector<ll>>(len+1, vector<ll>(2,0)));
    dp[0][0][1] = 1;
    for(ll idx=0; idx<len; idx++){
        for(ll count=0; count<=len; count++){
            for(ll tight=0; tight<2; tight++){
                if(dp[idx][count][tight]==0) continue;
                ll limit = (tight ? s[idx]-'0' : 1);
                for(ll d=0; d<=limit; d++){
                    ll nextcount = count+d;
                    bool nexttight = tight && (d==limit);
                    if(nextcount<=len){
                        dp[idx+1][nextcount][nexttight] = (dp[idx+1][nextcount][nexttight] + dp[idx][count][tight]) % mod;
                    }
                }
            }
        }
    }
    ll res = 0;
    for(ll i=1; i<=len; i++){
        if(steps[i]==k-1){
            res = (res+dp[len][i][0]) % mod;
            res = (res+dp[len][i][1]) % mod;
        }
    }
    if(k==1){
        res = (res-1+mod)%mod;
    }
    cout << res;
}