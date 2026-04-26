#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<pair<ll,ll>> v;
        for(int i=0; i<n; i++) v.push_back({arr[i], i});
        sort(v.rbegin(), v.rend());
        ll maxsofar = -1;
        ll res = 0;
        for(ll i=0; i<n; i++){
            if(arr[i]>=maxsofar){
                res++; maxsofar = arr[i];
            }
        }
        cout << res << "\n";
    }
}
// 3-4, 2,3, 2,1, 1-5, 1-2