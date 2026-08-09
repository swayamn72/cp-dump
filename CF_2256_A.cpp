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
        vi arr(3); cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr.begin(),arr.end());
        ll res = arr[2]-arr[0];

        vi arr2 = arr;
        arr2[2] = arr[0]+arr[1];
        res = min(res,arr2[2]-arr2[0]);
        vi arr3 = arr;
        arr3[0] = arr[1]+arr[2];
        sort(arr3.begin(),arr3.end());
        res = min(res,arr3[2]-arr3[0]);
        cout << res << "\n";
    }
}