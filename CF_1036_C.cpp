#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto calc = [](ll n)->ll{
        if(n==0) return 1;
        string s = to_string(n);
        ll len = s.size();
        vector<vector<vector<ll>>> dp(len+1,vector<vector<ll>>(4,vector<ll>(2,0)));
        dp[0][0][1] = 1;
        for(ll idx=0; idx<len; idx++){
            for(ll count=0; count<4; count++){
                for(ll tight=0; tight<2; tight++){
                    if(dp[idx][count][tight]==0) continue;
                    int allowed = (count==3 ? 0 : 9);
                    if(tight) allowed = min(allowed,s[idx]-'0');
                    for(ll d=0; d<=allowed; d++){
                        bool nexttight = tight && (d==(s[idx]-'0'));
                        if(d==0){
                            dp[idx+1][count][nexttight] += dp[idx][count][tight];
                        }else{
                            dp[idx+1][count+1][nexttight] += dp[idx][count][tight];
                        }
                    }
                }
            }
        }
        ll res = 0;
        for(ll count=0; count<4; count++){
            res += dp[len][count][0];
            res += dp[len][count][1];
        }
        return res;
    };

    ll t; cin >> t;
    while(t--){
        ll l,r; cin >> l >> r;
        cout << calc(r) - calc(l-1) << "\n";
    }
}