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
        sort(arr.rbegin(),arr.rend());
        ll res = 0; ll k = 0;
        ll maxv = (n+1)/2;
        for(ll i=0; i<n; i++){
            res += arr[i]/2;
            if(arr[i]%2){
                if(maxv>0){
                    res++; maxv--;
                }
            }
        }
        cout << res << "\n";
    }
}