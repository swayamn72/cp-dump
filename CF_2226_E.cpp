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
        vector<ll> res(n,0); res[0] = 1;
        multiset<ll> s;
        map<ll,ll> mp; 
        if(arr[0]!=0) mp[0] = arr[0];
        for(ll i=1; i<n; i++){
            res[i] = res[i-1];
            ll val = res[i];
        }
    }
}