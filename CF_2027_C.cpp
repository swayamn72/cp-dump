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
        vector<vector<ll>> v;
        for(ll i=0; i<n; i++){
            v.push_back({arr[i]-1+i+1,i});
        }
        sort(v.begin(),v.end());
        // for(auto a : v){
        //     cout << a[0] << " " << a[1] << "   ";
        // }
        ll res = n;
        set<ll> s; s.insert(n);
        for(auto a : v){
            if(s.count(a[0])){
                res = max(res,a[0]+a[1]);
                s.insert(a[0]+a[1]);
            }
        }
        cout << res << "\n";
    }
}