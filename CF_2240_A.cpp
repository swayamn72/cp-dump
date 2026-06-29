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
        ll n,k; cin >> n >> k;
        if(n<=k){
            cout << n << "\n";
            continue;
        }        
        ll res = 0;
        ll temp = n;
        for(ll i=1; i<=temp; i*=2){
            ll val = min(k,temp/i);
            res += val;
            temp -= (val*i);
        }
        cout << res << "\n";
    }
}