#include <algorithm>
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
        if(n==1){
            cout << arr[0] << "\n";
            continue;
        }else if(n==2){
            cout << max(arr[0],arr[1]) << "\n";
            continue;
        }
        ll maxv = *max_element(arr.begin(),arr.end());
        cout << max(maxv,max(arr[0],arr[n-1]) + (n-1)/2) << "\n";
    }
}