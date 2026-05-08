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
        ll res = 0, temp = 0;
        for(ll i=n-1; i>=0; i--){
            if(arr[i]+temp > 0) res++;
            temp += arr[i];
            temp = max({temp,arr[i],0LL});
        }    
        cout << res << "\n";
    }
}