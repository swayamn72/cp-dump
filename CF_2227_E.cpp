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
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        set<ll> s;
        vector<ll> suff(n);
        suff[n-1] = arr[n-1];
        for(ll i=n-2; i>=0; i--){
            suff[i] = suff[i+1];
            suff[i] = min(suff[i],arr[i]);
        } 
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        ll suffsum = accumulate(suff.begin(),suff.end(),0LL);
        ll res = sum - suffsum;
        ll maxv = 0;
        map<ll,ll> mp; for(auto a : suff) mp[a]++;
        for(auto a : mp){
            if(a.second>1) maxv = max(maxv,a.second-1);
        }
        res += maxv;
        cout << res << "\n";
    }
}