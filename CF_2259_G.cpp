#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi pref(n); pref[0] = 0;
        for(ll i=1; i<n; i++){
            pref[i] = (arr[i]-arr[i-1]);
        }        
        // for(auto a : pref) cout << a << " ";
        // cout << "\n";
        ll buffer = arr[n-1]-arr[n-2];
        ll last = buffer;
        ll num = 0;
        vi res(n);
        res[n-1] = 0;
        for(ll i=n-2; i>=1; i--){
            ll curr = buffer - last;
            ll diff = arr[i+1] - arr[i-1];
            if(i<=n-1) num++;
            if(diff<=k){
                res[i] = 0;
            }else{
                ll ans = (diff-k)*(num+1) - buffer;
                if(ans<0) ans = 0;
                res[i] = ans;
            }
            last = diff;
            buffer += (k-arr[i]+arr[i-1]);
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
} 