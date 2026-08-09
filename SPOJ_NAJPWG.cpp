#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll maxn = 1e5+1;
    vi phi(maxn);
    for(ll i=0; i<maxn; i++) phi[i] = i;
    for(ll i=2; i<maxn; i++){
        if(phi[i]==i){
            for(ll j=i; j<maxn; j+=i){
                phi[j] -= (phi[j]/i);
            }
        }
    }
    vi pref(maxn);
    pref[0] = phi[0];
    for(ll i=1; i<maxn; i++) pref[i] = pref[i-1] + phi[i];
    ll t; cin >> t;
    ll test = 1;
    while(t--){
        ll n; cin >> n;
        ll res = (n*(n+1))/2;
        res -= pref[n];
        cout << "Case " << test << ": " << res << "\n";
        test++;
    }
}