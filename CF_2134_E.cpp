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
    cin >> t;
    auto throwf = [&](ll v)->ll{
        cout << "throw " << v << endl;
        ll ans; cin >> ans;
        return ans;
    };
    auto swap = [&](ll v){
        cout << "swap " << v << endl;
    };
    while(t--){
        ll n; cin >> n;
        vector<bool> unknown(n+1,false);
        unknown[n] = true;
        vi dp(n+2);
        vi res(n+1);
        dp[n+1] = 0;
        dp[n] = 1;
        for(ll i=n-1; i>=1; i--){
            if(dp[i+1]==dp[i+2]){
                unknown[i] = true;
                dp[i] = 1 + dp[i+1];
                continue;
            }else{
                ll ans = throwf(i);
                if(ans==dp[i+1]+1) res[i] = 1;
                else res[i] = 2;
                dp[i] = ans;
            }
        }
        for(ll i=1; i<n; i++){
            if(!unknown[i]) continue;
            swap(i);
            ll ans = throwf(i+1);
            if(ans==dp[i+2]+1) res[i] = 1;
            else res[i] = 2;
        }
        swap(n-1);
        ll ans = throwf(n-1);
        if(ans==2) res[n] = 1;
        else res[n] = 2;

        cout << "! ";
        for(ll i=1; i<=n; i++) cout << res[i] << " ";
        cout << endl;
    }
} 
