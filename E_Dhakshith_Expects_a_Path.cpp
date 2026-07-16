#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,mod; cin >> n >> mod;
        vi fib(n+1); fib[0] = 1, fib[1] = 1;
        for(ll i=2; i<=n; i++){
            fib[i] = (fib[i-2]+fib[i-1])%mod;
        }
        ll inv2 = (mod+1)/2;
        ll sum1 = 1, sum2 = 1;
        ll dp = 1;
        for(ll i=2; i<=n; i++){
            ll val1 = (fib[i]*sum1)%mod;
            ll val2 = sum2;

            dp = (val1-val2+mod)%mod;
            dp = (dp*inv2)%mod;

            sum1 = (sum1+dp)%mod;
            sum2 = (sum2 + dp * fib[i])%mod;
        }
        cout << dp << "\n";
    }
}