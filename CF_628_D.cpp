#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m,d; cin >> m >> d;
    string a,b; cin >> a >> b;

    auto calc = [&](string &s)->ll{
        ll len = s.size();
        // len, m, tight
        vector<vector<vector<ll>>> dp(len+1, vector<vector<ll>>(m, vector<ll>(2,0)));
        dp[0][0][1] = 1;
        for(ll idx=0; idx<len; idx++){
            for(ll rem=0; rem<m; rem++){
                for(ll tight=0; tight<2; tight++){
                    if(dp[idx][rem][tight]==0) continue;
                    ll limit = (tight ? s[idx]-'0' : 9);
                    for(ll dig=0; dig<=limit; dig++){
                        if(idx%2 && dig!=d) continue;
                        if(idx%2==0 && dig==d) continue;
                        ll nextrem = (rem*10 + dig)%m;
                        bool nexttight = tight && (dig==limit);
                        dp[idx+1][nextrem][nexttight] = (dp[idx+1][nextrem][nexttight] + dp[idx][rem][tight])%mod;

                    }
                }
            }
        }
        ll ans = (dp[len][0][0] + dp[len][0][1])%mod;
        return ans;
    };
    ll res = (calc(b) - calc(a) + mod)%mod;
    bool flag = true;
    ll rema = 0;
    for(ll i=0; i<a.size(); i++){
        ll dig = a[i]-'0';
        if(i%2 && dig!=d) flag = false;
        if(i%2==0 && dig==d) flag = false;
        rema = (rema*10+dig)%m;
    }
    if(rema) flag = false;
    if(flag) res = (res+1)%mod;
    cout << res;
}