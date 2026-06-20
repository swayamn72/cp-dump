#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,k; cin >> n >> k;
    vi dp(k+1,0);
    auto binexp = [&](ll a, ll b){
        ll res = 1;
        while(b>0){
            if(b&1)res = (res*a)%mod;
            a = (a*a)%mod;
            b>>=1;
        }
        return res;
    };
    ll res = 0;
    for(ll i=k; i>=1; i--){
        ll count = (k/i);
        dp[i] = binexp(count,n);
        for(ll j=i*2; j<=k; j+=i){
            dp[i] = (dp[i]-dp[j]+mod)%mod;
        }
        res = (res + (i*dp[i])%mod)%mod;
    }
    cout << res;
}