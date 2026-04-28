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
        ll res = 0; ll temp = 0;
        for(ll i=0; i<n; i++){
            if(arr[i]==1){
                temp = 1;
            }else{
                res += arr[i];
                temp = 0;
            }
        }
        res += temp;
        cout << res << "\n";
    }
}