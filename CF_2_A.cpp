#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin >> n >> k;
    vi arr(n); for(auto &x : arr) cin >> x;
    double res = 1e18;
    double l=0, r=1e18;
    for(ll i=0; i<100; i++){
        ll m = l + (r-l)/2;
        ll count = 0;
        for(ll j=0; j<n; j++){
            count += arr[j]/m;
        }
        if(count >= k){
            res = m;
            l = m;
        }else{
            r = m;
        }
    }
}