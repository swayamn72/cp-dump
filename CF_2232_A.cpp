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
        sort(arr.begin(),arr.end());
        // map<ll,ll> mp; for(auto a : arr) mp[a]++;
        // if(mp.size()==1){
        //     cout << 0 << "\n";
        //     continue;    
        // }
        // ll minv = *min_element(arr.begin(),arr.end());
        // ll maxv = *max_element(arr.begin(),arr.end());
        // if(mp.size()==2){
        //     cout << (mp[minv]+1)/2 << "\n";
        //     continue;
        // }
        ll res = LLONG_MAX;
        for(ll i=0; i<n; i++){
            ll prev = 0, next = 0;
            for(ll j=0; j<n; j++){
                if(arr[j]<arr[i]) prev++;
                else if(arr[j]>arr[i]) next++;
            }
            res = min(res,max(prev,next));
        }
        cout << res << "\n";
    }
}