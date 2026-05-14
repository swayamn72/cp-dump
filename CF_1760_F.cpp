#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,c,d; cin >> n >> c >> d;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(*max_element(arr.begin(),arr.end())*d < c){
            cout << "Impossible" << "\n";
            continue;
        }
        sort(arr.rbegin(),arr.rend());
        vi pref(n); pref[0] = arr[0];
        for(ll i=1; i<n; i++) pref[i] = pref[i-1]+arr[i];
        if(pref[min(d,n)-1]>=c){
            cout << "Infinity" << "\n";
            continue;
        }
        // for(auto a : pref) cout << a << " ";
        // cout << "\n";
        // d = 4, c = 5
        // 2 3
        ll res = 0, left = 0, right = d;
        while(left<=right){
            ll mid = left+(right-left)/2; // 2
            ll window = mid+1; // 3
            ll div = d/window; // 1
            ll rem = d%window; // 1
            ll sum = pref[min(window,n)-1]*div; // 3
            if(rem!=0) sum += (pref[min(rem,n)-1]);
            if(sum>=c){
                res = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        cout << res << "\n";
    }
}