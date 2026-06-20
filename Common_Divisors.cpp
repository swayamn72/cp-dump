#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    ll maxn = 1e6+5;
    vi count(maxn,0); 
    
    for(ll i=0; i<n; i++){
        ll x; cin >> x; count[x]++;
    }
    for(ll i=maxn-1; i>=1; i--){
        ll ans = 0;
        for(ll j=i; j<maxn; j+=i){
            ans += count[j];
        }
        if(ans>=2){
            cout << i;
            return 0;
        }
    }
}