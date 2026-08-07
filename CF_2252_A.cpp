#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        ll sum = accumulate(arr.begin(),arr.end(),0LL);
        for(auto a : arr) mp[a]++;
        ll maxf = 0, maxv = 0;
        for(auto a : mp){
            if(a.second>maxf){
                maxf = a.second;
                maxv = a.first;
            }
        }
        ll toremove = max(0LL, 2*maxf-n-2);
        cout << sum - (toremove*maxv) << "\n";
    }
}