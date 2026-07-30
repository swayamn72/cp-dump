#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll res = 0;
    for(ll i=1; i<n-1; i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) res++;
    }
    cout << res;
}