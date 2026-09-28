#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi pref(n+1,0);
        pref[0] = 0;
        for(ll i=1; i<=n; i++) pref[i] = pref[i-1]+arr[i-1];
        // for(auto a : pref) cout << a << " ";
        // cout << "\n"; 
        vector<pair<ll,ll>> v;
        for(ll i=0; i<n; i++) v.push_back({pref[i],i});   
        sort(v.rbegin(),v.rend());
        vi res(n);
        for(ll i=0; i<v.size(); i++){
            res[v[i].second] = i+1;
        }    
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}