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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << arr[0] << "\n";
            continue;
        }
        ll ans = 0;
        for(ll i=0; i<n; i++){
            if(i&1) ans -= arr[i];
            else ans += arr[i];
        }        
        ll res = ans;
        if(n%2==0) res += (n-2);
        else res += (n-1);

        ll minu = 2e14, minv = 2e14;
        for(ll i=0; i<n; i++){
            if(i%2){
                minv = min(minv,i-2*arr[i]);
                if(minu!=2e14){
                    res = max(res,ans + (i+2*arr[i])-minu);
                }
            }else{
                minu = min(minu,i+2*arr[i]);  
                if(minv!=2e14){
                    res = max(res,ans + (i-2*arr[i])-minv);
                }  
            }
        }

        cout << res << "\n";
        
    }
}