#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,x,y,z; cin >> n >> x >> y >> z;
        ll left = 0, right = 10005;
        ll res = right;
        while(left<=right){
            ll mid = left + (right-left)/2;
            ll ans = x*mid; ans += y*mid;
            if(ans>=n){
                res = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        left = 0, right = 10005;
        ll res2 = right;
        while(left <= right){
            ll mid = left + (right-left)/2;
            ll ans = x*mid;
            if(mid>=z){
                ans += ((mid-z)*y*10);
            }
            if(ans>=n){
                res2 = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        cout << min(res,res2) << "\n";
    }
}