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
        sort(arr.begin(),arr.end());
        ll med = arr[n/2];
        ll res = 0;
        for(auto a : arr) res += abs(a-med);
        cout << res << " " << *max_element(arr.begin(),arr.end()) - *min_element(arr.begin(),arr.end());
        cout << "\n";        
    }
}