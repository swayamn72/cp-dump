#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll inf = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi dp(8,inf);
    dp[0] = 0;
    for(ll i=0; i<n; i++){
        ll c; cin >> c;
        string s; cin >> s;
        ll mask = 0;
        for(auto a : s){
            if(a=='A') mask |= 1;
            else if(a=='B') mask|=2;
            else mask |= 4;
        }
        vi nextdp = dp;
        for(ll i=0; i<8; i++){
            if(dp[i]==inf) continue;
            ll newmask = mask | i;
            nextdp[newmask] = min(nextdp[newmask],dp[i]+c);
        }
        dp = nextdp;
    }
    cout << (dp[7]==inf ? -1 : dp[7]);
}