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
        vector<vector<ll>> arr(n,vector<ll>(3));
        for(auto &a : arr){
            cin >> a[1] >> a[2];
            a[0] = a[1] + a[2];
        }
        sort(arr.begin(),arr.end());
        for(auto a : arr){
            cout << a[1] << " " << a[2] << " ";
        }
        cout << "\n";
    }
}