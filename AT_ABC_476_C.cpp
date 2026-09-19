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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        multiset<ll> s;
        s.insert(arr[0]);
        s.insert(arr[1]);
        for(ll i=2; i<n; i++){
            s.insert(arr[i]);
            auto it = s.end();
            it--; it--; it--;
            cout << *it << "\n";
        }        
    }
}