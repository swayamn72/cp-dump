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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi pref(n+1,0);
        // set<ll> s;
        for(ll i=0; i<n; i++){
            ll val = arr[i]*(i+1);
            ll right = val + (i);
            if(val<=n) pref[val]++;
            if(right<n) pref[right+1]--;
            // cout << val << " " << right << "  ";
        }
        vi res;
        ll curr = 0;
        for(ll i=0; i<n; i++){
            curr += pref[i];
            if(curr==0) res.push_back(i);
        }
        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
} 