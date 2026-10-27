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
        for(ll i=1; i<=n; i++) pref[i] = pref[i-1]+arr[i-1];
        ll maxv = *max_element(pref.begin(),pref.end());
        ll left = 0, right = 0;
        ll res = 0;
        while(left<=right){
            ll m = left+(right-left)/2;

            ll curr = 0;
            for(ll i=0; i<n; i++){
                if(curr>=m && curr+arr[i]<m){
                    curr = m;
                }else{
                    curr += arr[i];
                }
            }
            
        }
    }
}