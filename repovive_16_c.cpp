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
        ll left = 1, right = n;
        ll res = n;
        while(left<right){
            ll mid = left + (right-left)/2;
            ll pos2 = n - mid;
            ll pos1 = mid/2;
            if(pos1>=pos2){
                res = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        cout << res << "\n";
    }
}