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
        vi arr(3); for(auto &x : arr) cin >> x;
        ll res = 0;
        sort(arr.begin(),arr.end());
        while(arr[0]!=arr[1] && arr[1]!=arr[2]){
            res++;
            arr[0]++; arr[2]--;
            sort(arr.begin(),arr.end());
        }
        cout << res << "\n";
    }
}