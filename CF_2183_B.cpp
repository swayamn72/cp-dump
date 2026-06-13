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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        ll toremove = n-k+1;
        vector<ll> v;
        for(ll i=0; i<n; i++){
            if(toremove>0 && i>0 && arr[i]==arr[i-1]){
                toremove--;
            }else{
                v.push_back(arr[i]);
            }
        }        
        ll ptr = 0;
        for(ll i=0; i<v.size()-toremove; i++){
            if(v[i]==ptr) ptr++;
        }
        cout << ptr << "\n";
    }
}