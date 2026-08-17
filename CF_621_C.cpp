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
        ll n,p; cin >> n >> p;    
        vector<double> arr(n);
        for(ll i=0; i<n; i++){
            ll l,r; cin >> l >> r;
            ll primes = r/p - (l-1)/p;
            ll total = r-l+1;
            arr[i] = (double)primes/(double)total;
        }   
        double res = 0.0;
        for(ll i=0; i<n-1; i++){
            double val1 = arr[i], val2 = arr[i+1];
            double ans = val1 + val2 - val1*val2;
            ans *= 2000;
            res += ans;
        }
        double val1 = arr[n-1], val2 = arr[0];
        double ans = val1 + val2 - val1*val2;
        ans *= 2000;
        res += ans;
        cout << fixed << setprecision(7) << res;
    }
} 