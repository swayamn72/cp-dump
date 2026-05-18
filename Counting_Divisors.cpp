#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi res(1e6+1,1);

    for(ll i=2; i<=1e6; i++){
        for(ll j=i; j<=1e6; j+=i) res[j]++;
    }

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;        
        cout << res[n] << "\n";
    }
}