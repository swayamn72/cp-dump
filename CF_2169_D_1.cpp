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
        ll x,y,k; cin >> x >> y >> k;
        ll left = 1, right = 1000000000000LL;
        ll res = -1;
        while(left<=right){
            ll mid = left + (right-left)/2;
            ll len = mid;
            for(ll i=0; i<x; i++){
                len -= (len/y);
            }
            if(len>=k){
                right = mid-1;
                res = mid;
            }else{
                left = mid+1;
            }
        }        
        cout << res << "\n";
    }
}