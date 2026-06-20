#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t = 1;
    while(t--){
        ll n; cin >> n;
        string a,b; cin >> a >> b;
        ll res = 0;
        for(ll i=0; i<n; i++){
            ll diff = abs(a[i]-b[i]);
            if(diff>=5) diff = 10-diff;
            res += diff;
        }        
        cout << res << "\n";
    }
}