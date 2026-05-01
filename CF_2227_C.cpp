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
        vector<bool> vis(n,false);
        vector<ll> res(n); ll ptr1 = 0; ll ptr2 = n-1;
        for(ll i=0; i<n; i++){
            if(arr[i]%6==0){
                vis[i] = true;
                res[ptr1++] = arr[i];
            }
        }
        for(ll i=0; i<n; i++){
            if(arr[i]%2==0 && !vis[i]){
                vis[i] = true;
                res[ptr1++] = arr[i];
            }
        }
        for(ll i=0; i<n; i++){
            if(arr[i]%3==0 && !vis[i]){
                vis[i] = true;
                res[ptr2--] = arr[i];
            }
        }
        for(ll i=0; i<n; i++){
            if(!vis[i]){
                vis[i] = true;
                res[ptr1++] = arr[i];
            }
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}