#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(3); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        if(arr[0]+n<arr[1]){
            cout << arr[0]+n;
        }else{
            cout << "impossible";
        }
    }
}