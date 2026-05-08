#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n = 1e6;
    // 1 to n in n log log n
    vector<ll> phi(n+1);
    for(ll i=0; i<=n; i++) phi[i] = i;
    for(ll i=2; i<=n; i++){
        if(phi[i]==i){
            for(ll j=i; j<=n; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    ll t; cin >> t;
    while(t--){
        ll a; cin >> a;
        cout << phi[a] << "\n";
    }
}