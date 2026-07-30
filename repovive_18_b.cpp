#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res = 1;
        ll temp = 1;
        for(ll i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                temp++;
            }else{
                res = max(res,temp);
                temp = 1;
            }
        }
        res = max(res,temp);
        cout << n-res << "\n";
    }
}