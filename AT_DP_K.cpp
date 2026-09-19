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
    // cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<bool> dp(k+1);
        dp[0] = false;
        for(ll i=1; i<=k; i++){
            bool flag = false;
            for(auto a : arr){
                if(a>i) continue;
                if(!dp[i-a]){
                    flag = true;
                    break;
                }
            }
            dp[i] = flag;
        }
        cout << (dp[k] ? "First" : "Second");
    }
} 