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
        ll n,a,b; cin >> n >> a >> b;
        ll left = 0, right = min(n,b);
        while(right-left>5){
            ll mid1 = left + (right-left)/3;
            ll mid2 = right - (right-left)/3;
            ll ans1 = (b*(b+1))/2 - ((b-mid1)*((b-mid1)+1))/2; ans1 += (n-mid1)*a;
            ll ans2 = (b*(b+1))/2 - ((b-mid2)*((b-mid2)+1))/2; ans2 += (n-mid2)*a;
            if(ans1 > ans2){
                right = mid2;
            }else if(ans1 < ans2){
                left = mid1;
            }else{
                left = mid1; right = mid2;
            }
        }
        ll res = 0;
        for(ll i=left; i<=right; i++){
            res = max(res, (b*(b+1))/2 - ((b-i)*((b-i)+1))/2 + (n-i)*a);
        }
        cout << res << "\n";
    }
}
// 9 8 7 6  