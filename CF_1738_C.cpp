#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll even = 0, odd = 0;
        for(auto a : arr){
            if(a%2) odd++;
            else even++;
        }        
        vector<vector<vector<bool>>> dp(even+1,vector<vector<bool>>(odd+1, vector<bool>(2,false)));
        dp[0][0][0] = true;
        for(ll totalleft=1; totalleft<=n; totalleft++){
            for(ll x=0; x<=even; x++){
                ll y = totalleft-x;
                if(y<0 || y>odd) continue;
                int taken = n - totalleft;
                bool aliceturn;
                if(taken%2) aliceturn = false;
                else aliceturn = true;
                for(ll i=0; i<2; i++){
                    if(aliceturn){
                        bool canwin = false;
                        if(x>0) canwin |= dp[x-1][y][i];
                        if(y>0) canwin |= dp[x][y-1][i^1];
                        dp[x][y][i] = canwin;
                    }else{
                        bool canwin = true;
                        if(x>0) canwin &= dp[x-1][y][i];
                        if(y>0) canwin &= dp[x][y-1][i];
                        dp[x][y][i] = canwin;
                    }
                }
            }
        }
        if(dp[even][odd][0]) cout << "Alice" << "\n";
        else cout << "Bob" << "\n";
    }
}