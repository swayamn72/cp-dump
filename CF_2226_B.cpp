#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        ll res = 0;
        for(ll i=0; i<n-1; i++){
            ll gcdv = gcd(arr[i],arr[i+1]);
            ll val = abs(arr[i]-arr[i+1]);
            if(val==gcdv) res++;
        }        
        cout << res << "\n";
    }
}