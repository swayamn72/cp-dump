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
        ll res = 0;
        for(ll i=1; i<n; i++){
            if(arr[i]==arr[i-1] || arr[i]==arr[i-1]-1){
                res++;
                i++;
            }
        }
        cout << res << "\n";
    }
}