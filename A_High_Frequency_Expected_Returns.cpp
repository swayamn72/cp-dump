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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<double> p(n), q(n), s(n); 
        for(ll i=0; i<n; i++) cin >> p[i] >> q[i] >> s[i];
        double res = 0;
        for(ll i=0; i<n; i++){
            res += s[i]*(p[i]+q[i]);
        }
        cout << fixed << setprecision(6) << res;
    }
}