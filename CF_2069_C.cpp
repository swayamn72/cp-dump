#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll dp1 = 0, dp2 = 0, dp3 = 0;
        for(auto a : arr){
            if(a==1){
                dp1++;
            }else if(a==2){
                dp2 = (dp2*2 + dp1)%mod;
            }else{
                dp3 = (dp3+dp2) % mod;
            }
        }
        cout << dp3 << "\n";
    }
}