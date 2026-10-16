// Engineers are studying a signal with base level S and a cycle length M. They call an offset 
// t stable if adding it to the base level doesn't change the signal's "common factor" with the cycle."
// Formally, let g(x, y) denote the greatest common divisor of x and y. Count how many integers t satisfy:

// 0 ≤ t < M, and g(s, M) = g(s + t, M).

// Input The first line contains an integer T (1 ≤ T ≤ 50) - the number of scenarios. 
// Each of the next T lines contains two integers S and M (1 ≤ S < M < 10^10).
// Output For each scenario, print a single integer - the number of stable offsets t.

// gcd(s,m) = gcd(s+t,m) = g
// s = a*g    m = b*g    t = k*g
// gcd(a*g + k*g , b*g) = g
// gcd(a+k,b) = 1

// 0 <= t < m
// 0 <= k*g < b*g
// 0 <= k < b

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll s,m; cin >> s >> m;
        ll g = gcd(s,m);
        ll b = m/g;
        auto getphi = [](ll n)->ll{
            ll res = n;
            for(ll i=2; i*i<=n; i++){
                if(n%i==0){
                    while(n%i==0) n/=i;
                    res -= res/i;
                }
            }
            if(n>1) res -= res/n;
            return res;
        };
        cout << getphi(b) << "\n";
    }
}