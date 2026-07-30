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
        vi arr(2*n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << abs(arr[0]-arr[1]) << "\n";
            continue;
        }        
        ll ans = 0;
        for(auto a : arr) ans += abs(a);
        
        if(n%2){
            cout << ans << "\n";
            continue;
        }

        if(n==2){
            ll ans2 = 0;
            for(auto a : arr) ans2 += abs(a-2);
            ans = min(ans2,ans);
        }
        ll ans2 = 0;
        for(auto a : arr){
            ans2 += abs(a+1);
        }
        for(ll i=0; i<2*n; i++){
            ll a = arr[i];
            ans = min(ans,ans2-abs(a+1)+abs(a-n));
        }
        cout << ans << "\n";

    }
}