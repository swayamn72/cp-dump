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
        ll n,ax,ay,bx,by; cin >> n >> ax >> ay >> bx >> by;
        vector<ll> xarr(n); for(auto &x : xarr) cin >> x;
        vector<ll> yarr(n); for(auto &x : yarr) cin >> x;
        vector<vector<ll>> arr;
        for(ll i=0; i<n; i++){
            arr.push_back({xarr[i],yarr[i]});
        }
        arr.push_back({ax,ay}); arr.push_back({bx,by});
        sort(arr.begin(),arr.end());
        // for(auto a : arr) cout << a[0] << " " << a[1] << "\n";
        vector<vector<ll>> v;
        ll ptr = 0;
        v.push_back({arr[0][0],arr[0][1],arr[0][1]});
        for(ll i=1; i<arr.size(); i++){
            if(v[ptr][0] == arr[i][0]){
                v[ptr][1] = min(v[ptr][1], arr[i][1]);
                v[ptr][2] = max(v[ptr][2], arr[i][1]);
            }else{
                v.push_back({arr[i][0],arr[i][1],arr[i][1]});
                ptr++;
            }
        }
        // for(auto a : v) cout << a[0] << " " << a[1] << " " << a[2] << "\n";
        n = v.size();
        vector<ll> dp1(n,0), dp2(n,0);
        dp1[0] = 0; dp2[0] = 0;
        for(ll i=1; i<n; i++){
            ll curbottom = v[i][1], curtop = v[i][2];
            ll prevbottom = v[i-1][1], prevtop = v[i-1][2];
            ll dist = v[i][0] - v[i-1][0];
            // 1-top 2-bottom
            dp1[i] = dp1[i-1] + abs(prevtop-curbottom) + abs(curtop-curbottom);
            ll val = dp2[i-1] + abs(prevbottom-curbottom) + abs(curtop-curbottom);
            dp1[i] = min(dp1[i],val) + dist;

            dp2[i] = dp1[i-1] + abs(prevtop-curtop) + abs(curtop-curbottom);
            val = dp2[i-1] + abs(prevbottom-curtop) + abs(curtop-curbottom);
            dp2[i] = min(dp2[i],val) + dist;
        }
        cout << min(dp1[n-1],dp2[n-1]) << "\n";
    }
}