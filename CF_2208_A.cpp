#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n;
        map<ll,ll> mp;
        ll maxv = 0;
        for(ll i=0; i<n; i++) for(ll j=0; j<n; j++){
            ll val; cin >> val;
            mp[val]++;
            maxv = max(maxv, mp[val]);
        } 
        if(n==1){
            cout << "NO" << "\n";
            continue;
        }
        if(maxv > ((n-1)*(n-1))){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
    }
}